import glob
import os
import subprocess
from concurrent.futures import ThreadPoolExecutor
from datetime import datetime
from multiprocessing import freeze_support

import numpy as np
import pandas as pd

os.chdir(os.path.dirname(__file__))

now = datetime.now()
in_files = glob.glob("in/*.txt")
cnt = 0


def exec_cpp(seed: str):
    subprocess.run(f"./main < in/{seed}.txt > out/{seed}.txt", shell=True)
    global cnt
    cnt += 1
    print(f"finished {cnt}")


seeds = [os.path.basename(in_file).replace(".txt", "") for in_file in in_files]


def calc(weight: list[int], assign: list[int]):
    D = max(assign) + 1
    assign_weight = np.zeros(D)
    for i in range(len(assign)):
        assign_weight[assign[i]] += weight[i]
    variance = assign_weight.var()
    return 1 + np.round(100 * np.sqrt(variance))


if __name__ == "__main__":
    freeze_support()
    with ThreadPoolExecutor(max_workers=50) as executor:
        executor.map(exec_cpp, seeds)

    score = {"total": 0}

    for in_file in in_files:
        with open(in_file) as f:
            lines = f.readlines()
        weight = list(map(int, lines[-1].split()))
        with open(in_file.replace("in", "out")) as f:
            lines = f.readlines()
        assign = list(map(int, lines[-1].split()))
        score[os.path.basename(in_file)] = calc(weight, assign)
        score["total"] += score[os.path.basename(in_file)]

    csv_name = "./score.csv"
    df = pd.read_csv(csv_name, index_col=0)
    df[now.isoformat()] = score
    df.to_csv(csv_name)

    print(score["total"])
