# cpp標準エラー出力の最後の行を取得してスコア計算する


import glob
import os
import subprocess
from concurrent.futures import ThreadPoolExecutor
from multiprocessing import freeze_support

os.chdir(os.path.dirname(__file__))

in_files = glob.glob(os.path.join("in", "*.txt"))

score = 0


def exec_cpp(in_file: str):
    res = subprocess.run(f"./main < {in_file} > {in_file.replace('in', 'out')}", shell=True, stderr=subprocess.PIPE)
    s = int(res.stderr.decode().split("\n")[-2])
    global score
    score += s
    # print(os.path.basename(in_file), s)


if __name__ == "__main__":
    freeze_support()
    with ThreadPoolExecutor(max_workers=50) as executor:
        executor.map(exec_cpp, in_files)

    print(score)
