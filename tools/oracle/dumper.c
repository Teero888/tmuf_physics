/*
 * Per-tick physics state dumper, injected into TmForever.exe (TMUF 2.11.26,
 * SHA-256 4b6a7b31...d2d4) by launcher.exe.
 *
 * Hooks (always):
 *   CHmsZoneDynamic::PhysicsStep2   entry -> STEP record
 *   CHmsDyna::CopyTempToState        entry -> DYNA record (end-of-tick state)
 *
 * Output (little endian), path from TMUF_ORACLE_OUT (default oracle.bin):
 *   header: "TMOR" u32 version u32 dyna_state_size
 *   STEP:   u8 1, u32 step_index, u32 zone
 *   DYNA:   u8 2, u32 dyna, u8 state[dyna_state_size]
 *
 * TMUF_ORACLE_TRACE=physics adds, in the same stream:
 *   PRE:     u8 3, u32 dyna, u32 dt bits, u8 state[size]   CHmsDyna::DoPreCollisionDynamic
 *            entry (current state after the forces of the substep)
 *   CONTACT: u8 4, u32 car, u8 contact[0x60]               CSceneVehicleCar::AbsorbContact entry
 *   POST:    u8 5, u32 dyna, u8 state[size]                CHmsDyna::DoPostCollisionDynamic
 *            entry (after the collision response, before the replacement)
 *
 * TMUF_ORACLE_TRACE=feedback additionally writes TMUF_ORACLE_OUT.trace, a
 * text log of pack stream feedback: "I stream source offset size" when a
 * crypted stream starts reading (offset: position in the source, i.e. the
 * file inside the .pak), "F stream caller hexbytes" for every value the archive code mixes
 * into it (CClassicBufferCrypted::Write on a reading stream), followed by
 * likely return addresses further up the stack.
 *
 * TMUF_ORACLE_TRACE=plain additionally writes TMUF_ORACLE_OUT.plain, every
 * plain byte the pack readers produce (little endian records):
 *   'I' u32 stream u32 source u32 offset u32 size   crypted stream starts
 *   'O' u32 zlib u32 source 0 0                       zlib buffer opens
 *   'C' u32 stream u32 count 0 bytes[count]           BlowfishCBC_Read output
 *   'Z' u32 zlib u32 count 0 bytes[count]             CClassicBufferZlib::Read
 *
 * TMUF_ORACLE_TRACE=cells additionally writes TMUF_ORACLE_OUT.cells, the
 * static collision cells of every CHmsCollisionManager::SGroup in the order
 * GmOctree::Build receives them (SGroup::UpdateStaticCollisionTrees):
 *   u32 group u32 count, then count cells of 0x58 bytes (SColOctreeCell:
 *   +0x04 bounds center/half, +0x1c location, +0x4c surface, +0x50 corpus,
 *   +0x54 tree)
 *
 * TMUF_ORACLE_TRACE=stunts additionally writes TMUF_ORACLE_OUT.stunts, a
 * text line per scored stunt (CTrackManiaRace::ComputeStunt right before the
 * stunt event, the points final): "S step figure angle points" then the
 * pushed event arguments (the multiplier's float bits first) and the race's
 * dwords 0x124..0x17c (stunt state), all hex.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define ORACLE_VERSION 1

/* CHmsDyna: the temp state at +0x274 is copied to *(this+0x328) at the end
   of each tick, 0x2d dwords. */
#define DYNA_TEMP_STATE_OFFSET 0x274
#define DYNA_STATE_SIZE (0x2d * 4)

/* Saved state handed to handlers: stack[0] = eflags, stack[1..8] = pushad
   (edi esi ebp esp ebx edx ecx eax), stack[9] = return address, stack[10..]
   = stack arguments. */
enum { ST_RET = 9, ST_ARG0 = 10 };

typedef struct hook {
  const char *name;
  uintptr_t address;
  uint8_t expected[16];
  int stolen; /* bytes relocated to the trampoline, whole instructions */
  void (*handler)(void *self, const uint32_t *stack);
} hook;

static FILE *g_out;
static FILE *g_trace;
static FILE *g_plain;
static FILE *g_cells;
static uint32_t g_step;
static uint32_t g_dyna_records;

static void write_u8(uint8_t v) { fwrite(&v, 1, 1, g_out); }
static void write_u32(uint32_t v) { fwrite(&v, 4, 1, g_out); }

static void on_physics_step(void *zone, const uint32_t *stack) {
  (void)stack;
  write_u8(1);
  write_u32(g_step++);
  write_u32((uint32_t)(uintptr_t)zone);
}

static void on_copy_temp_to_state(void *dyna, const uint32_t *stack) {
  (void)stack;
  write_u8(2);
  write_u32((uint32_t)(uintptr_t)dyna);
  fwrite((const uint8_t *)dyna + DYNA_TEMP_STATE_OFFSET, DYNA_STATE_SIZE, 1, g_out);
  g_dyna_records++;
}

/* CHmsDyna: pointer to the current state at +0x32c */
#define DYNA_CURRENT_STATE_PTR 0x32c
#define CONTACT_SIZE 0x60

static void on_pre_collision(void *dyna, const uint32_t *stack) {
  write_u8(3);
  write_u32((uint32_t)(uintptr_t)dyna);
  write_u32(stack[ST_ARG0]);
  const uint8_t *state = *(const uint8_t *const *)((const uint8_t *)dyna + DYNA_CURRENT_STATE_PTR);
  fwrite(state, DYNA_STATE_SIZE, 1, g_out);
}

static void on_post_collision(void *dyna, const uint32_t *stack) {
  (void)stack;
  write_u8(5);
  write_u32((uint32_t)(uintptr_t)dyna);
  const uint8_t *state = *(const uint8_t *const *)((const uint8_t *)dyna + DYNA_CURRENT_STATE_PTR);
  fwrite(state, DYNA_STATE_SIZE, 1, g_out);
}

static void on_car_absorb_contact(void *car, const uint32_t *stack) {
  write_u8(4);
  write_u32((uint32_t)(uintptr_t)car);
  fwrite((const void *)(uintptr_t)stack[ST_ARG0], CONTACT_SIZE, 1, g_out);
}

typedef uint32_t(__attribute__((thiscall)) * buffer_get_offset_fn)(void *self);

/* CClassicBufferCrypted::Blowfish_InitForReading(CClassicBuffer *source, key,
   size): the IV is read at the source's current offset, i.e. the file's
   position inside the .pak. */
/* ---- return hooks: log a function's output buffer after it returns ---- */

typedef struct frame {
  uint32_t key; /* esp right after the hooked function's ret */
  uint32_t ret;
  uint32_t self, out;
  char kind;
  int used;
} frame;

static frame g_frames[512];
static volatile LONG g_frames_lock;
static uint8_t *g_ret_stub;

static void frames_lock(void) {
  while (InterlockedExchange(&g_frames_lock, 1))
    ;
}
static void frames_unlock(void) { InterlockedExchange(&g_frames_lock, 0); }

static void plain_record(char kind, uint32_t a, uint32_t b, uint32_t c, uint32_t d, const void *data, uint32_t n) {
  if (!g_plain)
    return;
  uint32_t words[4] = {a, b, c, d};
  fputc(kind, g_plain);
  fwrite(words, 4, 4, g_plain);
  if (n)
    fwrite(data, 1, n, g_plain);
}

/* Entry side: remember the call and send it to g_ret_stub on return.
   args_bytes: bytes the callee pops (ret N). */
static void hook_return(const uint32_t *stack, char kind, void *self, uint32_t out, uint32_t args_bytes) {
  uint32_t *s = (uint32_t *)stack;
  uint32_t key = (uint32_t)(uintptr_t)&s[ST_RET] + 4 + args_bytes;
  frames_lock();
  for (int i = 0; i < 512; i++)
    if (!g_frames[i].used) {
      g_frames[i] = (frame){key, s[ST_RET], (uint32_t)(uintptr_t)self, out, kind, 1};
      s[ST_RET] = (uint32_t)(uintptr_t)g_ret_stub;
      break;
    }
  frames_unlock();
}

/* Called from g_ret_stub: stack[0] eflags, [1..8] pushad, [9] slot for the
   real return address; &stack[10] is esp after the hooked ret. */
static void on_return(uint32_t *stack) {
  uint32_t key = (uint32_t)(uintptr_t)&stack[10];
  frame f = {0};
  frames_lock();
  for (int i = 0; i < 512; i++)
    if (g_frames[i].used && g_frames[i].key == key) {
      f = g_frames[i];
      g_frames[i].used = 0;
      break;
    }
  frames_unlock();
  stack[9] = f.ret;
  uint32_t count = stack[8]; /* eax */
  if (f.used && count && count < (64u << 20))
    plain_record(f.kind, f.self, count, 0, 0, (const void *)(uintptr_t)f.out, count);
}

static void on_crypted_read(void *stream, const uint32_t *stack) {
  hook_return(stack, 'C', stream, stack[ST_ARG0], 8);
}

static void on_zlib_read(void *zlib, const uint32_t *stack) { hook_return(stack, 'Z', zlib, stack[ST_ARG0], 8); }

static void on_zlib_open(void *zlib, const uint32_t *stack) {
  plain_record('O', (uint32_t)(uintptr_t)zlib, stack[ST_ARG0], 0, 0, NULL, 0);
}

static void make_ret_stub(void) {
  uint8_t *p = VirtualAlloc(NULL, 64, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
  g_ret_stub = p;
  *p++ = 0x83, *p++ = 0xec, *p++ = 0x04; /* sub esp, 4 */
  *p++ = 0x60;                           /* pushad */
  *p++ = 0x9c;                           /* pushfd */
  *p++ = 0x54;                           /* push esp */
  *p++ = 0xe8;
  int32_t rel = (int32_t)((uintptr_t)on_return - (uintptr_t)(p + 4));
  memcpy(p, &rel, 4);
  p += 4;
  *p++ = 0x83, *p++ = 0xc4, *p++ = 0x04; /* add esp, 4 */
  *p++ = 0x9d;                           /* popfd */
  *p++ = 0x61;                           /* popad */
  *p++ = 0xc3;                           /* ret */
  FlushInstructionCache(GetCurrentProcess(), g_ret_stub, (SIZE_T)(p - g_ret_stub));
}

static void on_crypted_init_read(void *stream, const uint32_t *stack) {
  void *source = (void *)(uintptr_t)stack[ST_ARG0];
  uint32_t offset = 0xffffffffu;
  if (source) {
    buffer_get_offset_fn get_offset = (buffer_get_offset_fn)(*(void ***)source)[0x14 / 4];
    offset = get_offset(source);
  }
  if (g_trace)
    fprintf(g_trace, "I %08x %08x %08x %08x\n", (unsigned)(uintptr_t)stream, (unsigned)(uintptr_t)source,
            (unsigned)offset, (unsigned)stack[ST_ARG0 + 2]);
  plain_record('I', (uint32_t)(uintptr_t)stream, (uint32_t)(uintptr_t)source, offset, stack[ST_ARG0 + 2], NULL, 0);
}

/* CClassicBufferCrypted::Write(const void *data, unsigned n).
   The stream is reading when *(this+8) != 0; then Write only mixes feedback. */
static void on_crypted_write(void *stream, const uint32_t *stack) {
  if (!g_trace || *(const uint32_t *)((const uint8_t *)stream + 8) == 0)
    return;
  const uint8_t *data = (const uint8_t *)(uintptr_t)stack[ST_ARG0];
  uint32_t n = stack[ST_ARG0 + 1];
  fprintf(g_trace, "F %08x %08x ", (unsigned)(uintptr_t)stream, (unsigned)stack[ST_RET]);
  for (uint32_t i = 0; i < n && i < 64; i++)
    fprintf(g_trace, "%02x", data[i]);
  /* Heuristic call chain: further stack words that point into .text. The
     game runs loaders on fibers with small stacks, so stay inside the
     committed region. */
  MEMORY_BASIC_INFORMATION mbi;
  const uint32_t *limit = stack + ST_ARG0 + 2;
  if (VirtualQuery(stack, &mbi, sizeof mbi))
    limit = (const uint32_t *)((const uint8_t *)mbi.BaseAddress + mbi.RegionSize);
  int found = 0;
  for (int i = ST_ARG0 + 2; i < ST_ARG0 + 64 && stack + i < limit && found < 6; i++) {
    uint32_t v = stack[i];
    if (v >= 0x00401000 && v < 0x00a2c000) {
      fprintf(g_trace, " %08x", (unsigned)v);
      found++;
    }
  }
  fputc('\n', g_trace);
}

#define COL_CELL_SIZE 0x58

/* SGroup::UpdateStaticCollisionTrees right before GmOctree::Build: the
   collected cells are the local CFastBuffer at [esp+0x1c] (count, data);
   ebp is the group. */
static void on_static_cells(void *self, const uint32_t *stack) {
  (void)self;
  const uint32_t *esp = stack + 9;
  uint32_t group = stack[3], count = esp[7];
  const uint8_t *cells = (const uint8_t *)(uintptr_t)esp[8];
  fwrite(&group, 4, 1, g_cells);
  fwrite(&count, 4, 1, g_cells);
  if (count && cells)
    fwrite(cells, COL_CELL_SIZE, count, g_cells);
  fflush(g_cells);
}

static FILE *g_stunts;

/* in CTrackManiaRace::ComputeStunt before the event call: edi figure, eax
   angle (degrees), ebx points, esi the race; [esp] the multiplier (float) */
static void on_stunt(void *self, const uint32_t *stack) {
  (void)self;
  const uint8_t *race = (const uint8_t *)(uintptr_t)stack[2];
  const uint32_t *esp = stack + 9;
  fprintf(g_stunts, "S %u %u %u %u", g_step, stack[1], stack[8], stack[5]);
  for (int i = 0; i < 5; i++)
    fprintf(g_stunts, " %08x", esp[i]);
  for (uint32_t off = 0x124; off < 0x180; off += 4)
    fprintf(g_stunts, " %08x", *(const uint32_t *)(race + off));
  fputc('\n', g_stunts);
  fflush(g_stunts);
}

static hook g_stunt_hooks[] = {
    {"CTrackManiaRace::ComputeStunt/event", 0x004b3ce1, {0x53, 0x50, 0x57, 0x8b, 0xce}, 5, on_stunt},
};

static hook g_cells_hooks[] = {
    {"SGroup::UpdateStaticCollisionTrees/Build", 0x0053ad75, {0xd9, 0xee, 0x8b, 0x44, 0x24, 0x20}, 6, on_static_cells},
};

static hook g_hooks[] = {
    {"CHmsZoneDynamic::PhysicsStep2", 0x00549b60, {0x55, 0x8b, 0xec, 0x83, 0xe4, 0xf8}, 6, on_physics_step},
    {"CHmsDyna::CopyTempToState",
     0x00532c30,
     {0x56, 0x8b, 0xc1, 0x57, 0x8b, 0xb8, 0x28, 0x03, 0x00, 0x00},
     10,
     on_copy_temp_to_state},
};

static hook g_physics_hooks[] = {
    {"CHmsDyna::DoPreCollisionDynamic", 0x00535bd0, {0x55, 0x8b, 0xec, 0x83, 0xe4, 0xf8}, 6, on_pre_collision},
    {"CHmsDyna::DoPostCollisionDynamic",
     0x005362d0,
     {0x83, 0xec, 0x0c, 0x56, 0x8d, 0x44, 0x24, 0x04},
     8,
     on_post_collision},
    {"CSceneVehicleCar::AbsorbContact", 0x007c2f10, {0x83, 0xec, 0x30, 0x56, 0x57}, 5, on_car_absorb_contact},
};

static hook g_plain_hooks[] = {
    {"CClassicBufferCrypted::BlowfishCBC_Read", 0x009113a0, {0x83, 0xec, 0x14, 0x53, 0x55, 0x56}, 6, on_crypted_read},
    {"CClassicBufferZlib::Read", 0x00910c60, {0x53, 0x8b, 0x59, 0x10, 0x56}, 5, on_zlib_read},
    {"CClassicBufferZlib::OpenForReading", 0x009109c0, {0x8b, 0x44, 0x24, 0x04, 0x56}, 5, on_zlib_open},
};

static hook g_trace_hooks[] = {
    {"CClassicBufferCrypted::Blowfish_InitForReading",
     0x009112c0,
     {0x6a, 0xff, 0x68, 0xdb, 0x1a, 0xae, 0x00},
     7,
     on_crypted_init_read},
    {"CClassicBufferCrypted::Write", 0x00911890, {0x56, 0x8b, 0xf1, 0x83, 0x7e, 0x14, 0x00}, 7, on_crypted_write},
};

static void log_msg(const char *fmt, const char *a, unsigned b) {
  char buf[512];
  snprintf(buf, sizeof buf, fmt, a, b);
  OutputDebugStringA(buf);
  fprintf(stderr, "%s\n", buf);
}

static void put_rel32(uint8_t *at, uintptr_t from_next, uintptr_t to) {
  int32_t rel = (int32_t)(to - from_next);
  memcpy(at, &rel, 4);
}

/*
 * Trampoline: pushad; pushfd; push esp; push ecx; call handler; add esp,8;
 * popfd; popad; <stolen bytes>; jmp target+stolen. Handlers must not touch
 * the FPU, the game keeps its own x87 control word during simulation.
 */
static int install(hook *h) {
  uint8_t *target = (uint8_t *)h->address;
  if (memcmp(target, h->expected, (size_t)h->stolen) != 0) {
    log_msg("[oracle] %s: unexpected bytes at 0x%08x, not hooking", h->name, (unsigned)h->address);
    return 0;
  }
  uint8_t *t = VirtualAlloc(NULL, 64, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
  if (!t)
    return 0;
  uint8_t *p = t;
  *p++ = 0x60; /* pushad */
  *p++ = 0x9c; /* pushfd */
  *p++ = 0x54; /* push esp */
  *p++ = 0x51; /* push ecx */
  *p++ = 0xe8;
  put_rel32(p, (uintptr_t)(p + 4), (uintptr_t)h->handler);
  p += 4;
  *p++ = 0x83, *p++ = 0xc4, *p++ = 0x08; /* add esp, 8 */
  *p++ = 0x9d;                           /* popfd */
  *p++ = 0x61;                           /* popad */
  memcpy(p, target, (size_t)h->stolen);
  p += h->stolen;
  *p++ = 0xe9;
  put_rel32(p, (uintptr_t)(p + 4), h->address + (uintptr_t)h->stolen);
  p += 4;
  FlushInstructionCache(GetCurrentProcess(), t, (SIZE_T)(p - t));

  DWORD old;
  if (!VirtualProtect(target, (SIZE_T)h->stolen, PAGE_EXECUTE_READWRITE, &old))
    return 0;
  target[0] = 0xe9;
  put_rel32(target + 1, h->address + 5, (uintptr_t)t);
  for (int i = 5; i < h->stolen; i++)
    target[i] = 0x90;
  VirtualProtect(target, (SIZE_T)h->stolen, old, &old);
  FlushInstructionCache(GetCurrentProcess(), target, (SIZE_T)h->stolen);
  log_msg("[oracle] hooked %s at 0x%08x", h->name, (unsigned)h->address);
  return 1;
}

BOOL WINAPI DllMain(HINSTANCE inst, DWORD reason, LPVOID reserved) {
  (void)inst;
  (void)reserved;
  if (reason == DLL_PROCESS_ATTACH) {
    char path[MAX_PATH], trace[64];
    DWORD n = GetEnvironmentVariableA("TMUF_ORACLE_OUT", path, sizeof path);
    if (n == 0 || n >= sizeof path - 8)
      strcpy(path, "oracle.bin");
    g_out = fopen(path, "wb");
    if (!g_out) {
      log_msg("[oracle] cannot open %s (%u)", path, (unsigned)GetLastError());
      return FALSE;
    }
    setvbuf(g_out, NULL, _IOFBF, 1 << 20);
    fwrite("TMOR", 4, 1, g_out);
    write_u32(ORACLE_VERSION);
    write_u32(DYNA_STATE_SIZE);
    for (size_t i = 0; i < sizeof g_hooks / sizeof g_hooks[0]; i++)
      if (!install(&g_hooks[i]))
        return FALSE;

    n = GetEnvironmentVariableA("TMUF_ORACLE_TRACE", trace, sizeof trace);
    int want_feedback = n > 0 && n < sizeof trace && strstr(trace, "feedback");
    int want_plain = n > 0 && n < sizeof trace && strstr(trace, "plain");
    if (n > 0 && n < sizeof trace && strstr(trace, "cells")) {
      char cells_path[MAX_PATH + 16];
      snprintf(cells_path, sizeof cells_path, "%s.cells", path);
      g_cells = fopen(cells_path, "wb");
      if (!g_cells)
        return FALSE;
      for (size_t i = 0; i < sizeof g_cells_hooks / sizeof g_cells_hooks[0]; i++)
        if (!install(&g_cells_hooks[i]))
          return FALSE;
    }
    if (n > 0 && n < sizeof trace && strstr(trace, "stunts")) {
      char stunts_path[MAX_PATH + 16];
      snprintf(stunts_path, sizeof stunts_path, "%s.stunts", path);
      g_stunts = fopen(stunts_path, "w");
      if (!g_stunts)
        return FALSE;
      for (size_t i = 0; i < sizeof g_stunt_hooks / sizeof g_stunt_hooks[0]; i++)
        if (!install(&g_stunt_hooks[i]))
          return FALSE;
    }
    if (n > 0 && n < sizeof trace && strstr(trace, "physics"))
      for (size_t i = 0; i < sizeof g_physics_hooks / sizeof g_physics_hooks[0]; i++)
        if (!install(&g_physics_hooks[i]))
          return FALSE;
    char extra[MAX_PATH + 16];
    if (want_feedback) {
      snprintf(extra, sizeof extra, "%s.trace", path);
      g_trace = fopen(extra, "w");
      if (!g_trace)
        return FALSE;
      setvbuf(g_trace, NULL, _IOFBF, 1 << 20);
    }
    if (want_plain) {
      snprintf(extra, sizeof extra, "%s.plain", path);
      g_plain = fopen(extra, "wb");
      if (!g_plain)
        return FALSE;
      setvbuf(g_plain, NULL, _IOFBF, 1 << 22);
      make_ret_stub();
      for (size_t i = 0; i < sizeof g_plain_hooks / sizeof g_plain_hooks[0]; i++)
        if (!install(&g_plain_hooks[i]))
          return FALSE;
    }
    if (want_feedback || want_plain)
      for (size_t i = 0; i < sizeof g_trace_hooks / sizeof g_trace_hooks[0]; i++)
        if (!install(&g_trace_hooks[i]))
          return FALSE;
  } else if (reason == DLL_PROCESS_DETACH) {
    if (g_out) {
      fclose(g_out);
      g_out = NULL;
    }
    if (g_trace) {
      fclose(g_trace);
      g_trace = NULL;
    }
    if (g_plain) {
      fclose(g_plain);
      g_plain = NULL;
    }
    if (g_cells) {
      fclose(g_cells);
      g_cells = NULL;
    }
    if (g_stunts) {
      fclose(g_stunts);
      g_stunts = NULL;
    }
    char steps[16];
    snprintf(steps, sizeof steps, "%u", g_step);
    log_msg("[oracle] done: %s steps, %u dyna records", steps, g_dyna_records);
  }
  return TRUE;
}
