# Windows 32-bit tools, built with MinGW (runs under Wine).
CC = i686-w64-mingw32-gcc
CFLAGS = -O2 -Wall -Wextra -std=c11
OUT = build

all: $(OUT)/dumper.dll $(OUT)/launcher.exe

$(OUT)/dumper.dll: dumper.c | $(OUT)
	$(CC) $(CFLAGS) -shared -static-libgcc -o $@ $<

$(OUT)/launcher.exe: launcher.c | $(OUT)
	$(CC) $(CFLAGS) -static-libgcc -o $@ $<

$(OUT):
	mkdir -p $@

clean:
	rm -rf $(OUT)

.PHONY: all clean
