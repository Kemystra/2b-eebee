import glob
import subprocess
import os


# Folders with cpp files
SRC_FOLDER = [
    ".",
    "upgrades"
]

BUILD_FOLDER = "build"

patterns = [f"{x}/*.cpp" for x in SRC_FOLDER]
cpp_files = []

for p in patterns:
    cpp_files.extend(glob.glob(p))

cpp_files_no_ext = [os.path.splitext(x)[0] for x in cpp_files]


# Compile to object files
obj_files = [f"{BUILD_FOLDER}/{x}.o" for x in cpp_files_no_ext]
for i, f in enumerate(cpp_files):
    subprocess.run(["g++", f, "-c", "-o", obj_files[i]])

# Final compile
compile_command = ["g++"]
compile_command.extend(obj_files)
compile_command.extend(["-c", "main.exe"])
