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
 * TMUF_ORACLE_TRACE=feedback additionally writes TMUF_ORACLE_OUT.trace, a
 * text log of pack stream feedback: "I stream" when a crypted stream starts
 * reading, "F stream caller hexbytes" for every value the archive code mixes
 * into it (CClassicBufferCrypted::Write on a reading stream), followed by
 * likely return addresses further up the stack.
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

static void on_crypted_init_read(void *stream, const uint32_t *stack) {
  (void)stack;
  fprintf(g_trace, "I %08x\n", (unsigned)(uintptr_t)stream);
}

/* CClassicBufferCrypted::Write(const void *data, unsigned n).
   The stream is reading when *(this+8) != 0; then Write only mixes feedback. */
static void on_crypted_write(void *stream, const uint32_t *stack) {
  if (*(const uint32_t *)((const uint8_t *)stream + 8) == 0)
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

static hook g_hooks[] = {
    {"CHmsZoneDynamic::PhysicsStep2", 0x00549b60, {0x55, 0x8b, 0xec, 0x83, 0xe4, 0xf8}, 6, on_physics_step},
    {"CHmsDyna::CopyTempToState",
     0x00532c30,
     {0x56, 0x8b, 0xc1, 0x57, 0x8b, 0xb8, 0x28, 0x03, 0x00, 0x00},
     10,
     on_copy_temp_to_state},
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
    if (n > 0 && n < sizeof trace && strstr(trace, "feedback")) {
      strcat(path, ".trace");
      g_trace = fopen(path, "w");
      if (!g_trace)
        return FALSE;
      setvbuf(g_trace, NULL, _IOFBF, 1 << 20);
      for (size_t i = 0; i < sizeof g_trace_hooks / sizeof g_trace_hooks[0]; i++)
        if (!install(&g_trace_hooks[i]))
          return FALSE;
    }
  } else if (reason == DLL_PROCESS_DETACH) {
    if (g_out) {
      fclose(g_out);
      g_out = NULL;
    }
    if (g_trace) {
      fclose(g_trace);
      g_trace = NULL;
    }
    char steps[16];
    snprintf(steps, sizeof steps, "%u", g_step);
    log_msg("[oracle] done: %s steps, %u dyna records", steps, g_dyna_records);
  }
  return TRUE;
}
