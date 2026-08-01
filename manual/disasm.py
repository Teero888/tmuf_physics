import subprocess
from capstone import *

# Run objdump
cmd = "objdump -d -M intel /home/teero/software/tmnf_physics/exe/TmForeverFixed.exe"
print("Running objdump...")
# Actually, just use objdump directly in bash.
