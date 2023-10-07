import os
import subprocess
import sys

file = sys.argv[1]
dir = os.path.dirname(file)

with open(file, "r") as f:
    source = f.read()
tmp_file = file.replace(".cpp", "-combined.cpp")
subprocess.run(f"oj-bundle {file} > {tmp_file}", shell=True)
subprocess.run(f"g++-12 -std=c++20 {tmp_file} -o {file.replace('.cpp', '')} && atcoder-tools submit --dir={dir} --code={tmp_file} -u --config=.atcodertools.toml", shell=True)
with open(file, "w") as f:
    f.write(source)
