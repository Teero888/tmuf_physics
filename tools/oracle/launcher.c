/*
 * Starts TmForever.exe with dumper.dll loaded before any game code runs.
 *
 *   launcher.exe DLL_PATH EXE_PATH [game args...]
 *
 * The entry point is patched to spin (EB FE) so the loader finishes first,
 * then LoadLibraryA runs in a remote thread, then the entry bytes are restored.
 */
#include <stdio.h>
#include <string.h>
#include <windows.h>

static int fail(const char *what) {
  fprintf(stderr, "launcher: %s failed (%lu)\n", what, GetLastError());
  return 1;
}

static DWORD entry_point_rva(const char *exe) {
  HANDLE f = CreateFileA(exe, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
  if (f == INVALID_HANDLE_VALUE)
    return 0;
  IMAGE_DOS_HEADER dos;
  IMAGE_NT_HEADERS32 nt;
  DWORD got = 0;
  DWORD rva = 0;
  if (ReadFile(f, &dos, sizeof dos, &got, NULL) && got == sizeof dos &&
      SetFilePointer(f, dos.e_lfanew, NULL, FILE_BEGIN) != INVALID_SET_FILE_POINTER &&
      ReadFile(f, &nt, sizeof nt, &got, NULL) && got == sizeof nt)
    rva = nt.OptionalHeader.AddressOfEntryPoint;
  CloseHandle(f);
  return rva;
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "usage: launcher.exe DLL_PATH EXE_PATH [args...]\n");
    return 2;
  }
  char dll[MAX_PATH];
  if (!GetFullPathNameA(argv[1], sizeof dll, dll, NULL))
    return fail("GetFullPathName");

  char cmdline[8192];
  snprintf(cmdline, sizeof cmdline, "\"%s\"", argv[2]);
  /* Game args like /validatepath=dir\ end in a backslash, which would escape
     a closing quote, so only quote args that need it. */
  for (int i = 3; i < argc; i++) {
    int quote = strchr(argv[i], ' ') != NULL;
    strncat(cmdline, quote ? " \"" : " ", sizeof cmdline - strlen(cmdline) - 1);
    strncat(cmdline, argv[i], sizeof cmdline - strlen(cmdline) - 1);
    if (quote)
      strncat(cmdline, "\"", sizeof cmdline - strlen(cmdline) - 1);
  }

  DWORD rva = entry_point_rva(argv[2]);
  if (!rva)
    return fail("reading entry point");

  STARTUPINFOA si;
  ZeroMemory(&si, sizeof si);
  si.cb = sizeof si;
  PROCESS_INFORMATION pi;
  if (!CreateProcessA(argv[2], cmdline, NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi))
    return fail("CreateProcess");

  /* The exe has no ASLR: image base 0x400000. */
  LPVOID entry = (LPVOID)(uintptr_t)(0x400000 + rva);
  unsigned char orig[2], spin[2] = {0xeb, 0xfe};
  SIZE_T n;
  DWORD old;
  if (!VirtualProtectEx(pi.hProcess, entry, 2, PAGE_EXECUTE_READWRITE, &old) ||
      !ReadProcessMemory(pi.hProcess, entry, orig, 2, &n) ||
      !WriteProcessMemory(pi.hProcess, entry, spin, 2, &n))
    return fail("patching entry point");
  FlushInstructionCache(pi.hProcess, entry, 2);
  ResumeThread(pi.hThread);

  CONTEXT ctx;
  int reached = 0;
  for (int i = 0; i < 2000 && !reached; i++) {
    Sleep(5);
    SuspendThread(pi.hThread);
    ctx.ContextFlags = CONTEXT_CONTROL;
    if (GetThreadContext(pi.hThread, &ctx) && ctx.Eip == (DWORD)(uintptr_t)entry)
      reached = 1;
    else
      ResumeThread(pi.hThread);
  }
  if (!reached) {
    TerminateProcess(pi.hProcess, 1);
    return fail("waiting for entry point");
  }

  LPVOID remote = VirtualAllocEx(pi.hProcess, NULL, sizeof dll, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
  if (!remote || !WriteProcessMemory(pi.hProcess, remote, dll, strlen(dll) + 1, &n))
    return fail("writing dll path");
  LPTHREAD_START_ROUTINE load =
      (LPTHREAD_START_ROUTINE)(void *)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
  HANDLE t = CreateRemoteThread(pi.hProcess, NULL, 0, load, remote, 0, NULL);
  if (!t)
    return fail("CreateRemoteThread");
  WaitForSingleObject(t, INFINITE);
  DWORD module = 0;
  GetExitCodeThread(t, &module);
  CloseHandle(t);
  if (!module) {
    TerminateProcess(pi.hProcess, 1);
    fprintf(stderr, "launcher: LoadLibrary(%s) failed in the game\n", dll);
    return 1;
  }

  if (!WriteProcessMemory(pi.hProcess, entry, orig, 2, &n))
    return fail("restoring entry point");
  VirtualProtectEx(pi.hProcess, entry, 2, old, &old);
  FlushInstructionCache(pi.hProcess, entry, 2);
  ResumeThread(pi.hThread);

  WaitForSingleObject(pi.hProcess, INFINITE);
  DWORD code = 0;
  GetExitCodeProcess(pi.hProcess, &code);
  return (int)code;
}
