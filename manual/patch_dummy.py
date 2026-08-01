import re

with open("scratch_ComputeForcesModel3.cpp", "r") as f:
    orig = f.read()

dummy_code = """static uint8_t g_dummy_buffer[2048];
struct DummyInit {
    DummyInit() {
        for(int i=0; i<256; i++) {
            ((void**)g_dummy_buffer)[i] = &g_dummy_buffer[1024];
        }
    }
} g_dummy_init;
static void* g_dummy_ptr = &g_dummy_buffer[0];"""

orig = orig.replace("static uint8_t g_dummy_buffer[1024];\nstatic void* g_dummy_ptr = &g_dummy_buffer[0];", dummy_code)

with open("scratch_ComputeForcesModel3.cpp", "w") as f:
    f.write(orig)
print("Patched dummy")
