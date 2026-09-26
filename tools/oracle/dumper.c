/*
 * Per-tick physics state dumper, injected into TmForever.exe (TMUF 2.11.26,
 * SHA-256 4b6a7b31...d2d4) by launcher.exe.
 *
 * Hooks:
 *   CHmsZoneDynamic::PhysicsStep2   entry -> STEP record
 *   CHmsDyna::CopyTempToState        entry -> DYNA record (end-of-tick state)
 *
 * Output (little endian), path from TMUF_ORACLE_OUT (default oracle.bin):
 *   header: "TMOR" u32 version u32 dyna_state_size
 *   STEP:   u8 1, u32 step_index, u32 zone
 *   DYNA:   u8 2, u32 dyna, u8 state[dyna_state_size]
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

#define ORACLE_VERSION 1

/* CHmsDyna: the temp state at +0x274 is copied to *(this+0x328) at the end
   of each tick, 0x2d dwords. */
#define DYNA_TEMP_STATE_OFFSET 0x274
#define DYNA_STATE_SIZE (0x2d * 4)

typedef struct hook {
  const char *name;
  uintptr_t address;
  uint8_t expected[16];
  int stolen; /* bytes relocated to the trampoline, whole instructions */
  void (*handler)(void *self);
} hook;

static FILE *g_out;
static uint32_t g_step;
static uint32_t g_dyna_records;

static void write_u8(uint8_t v) { fwrite(&v, 1, 1, g_out); }
static void write_u32(uint32_t v) { fwrite(&v, 4, 1, g_out); }

static void on_physics_step(void *zone) {
  write_u8(1);
  write_u32(g_step++);
  write_u32((uint32_t)(uintptr_t)zone);
}

static void on_copy_temp_to_state(void *dyna) {
  write_u8(2);
  write_u32((uint32_t)(uintptr_t)dyna);
  fwrite((const uint8_t *)dyna + DYNA_TEMP_STATE_OFFSET, DYNA_STATE_SIZE, 1, g_out);
  g_dyna_records++;
}

static hook g_hooks[] = {
    {"CHmsZoneDynamic::PhysicsStep2", 0x00549b60,
     {0x55, 0x8b, 0xec, 0x83, 0xe4, 0xf8}, 6, on_physics_step},
    {"CHmsDyna::CopyTempToState", 0x00532c30,
     {0x56, 0x8b, 0xc1, 0x57, 0x8b, 0xb8, 0x28, 0x03, 0x00, 0x00}, 10, on_copy_temp_to_state},
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
 * Trampoline: pushad; pushfd; push ecx; call handler; add esp,4; popfd;
 * popad; <stolen bytes>; jmp target+stolen. Handlers must not touch the FPU,
 * the game keeps its own x87 control word during simulation.
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
  *p++ = 0x60;
  *p++ = 0x9c;
  *p++ = 0x51;
  *p++ = 0xe8;
  put_rel32(p, (uintptr_t)(p + 4), (uintptr_t)h->handler);
  p += 4;
  *p++ = 0x83, *p++ = 0xc4, *p++ = 0x04;
  *p++ = 0x9d;
  *p++ = 0x61;
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
    char path[MAX_PATH];
    DWORD n = GetEnvironmentVariableA("TMUF_ORACLE_OUT", path, sizeof path);
    if (n == 0 || n >= sizeof path)
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
  } else if (reason == DLL_PROCESS_DETACH) {
    if (g_out) {
      fclose(g_out);
      g_out = NULL;
    }
    char steps[16];
    snprintf(steps, sizeof steps, "%u", g_step);
    log_msg("[oracle] done: %s steps, %u dyna records", steps, g_dyna_records);
  }
  return TRUE;
}
