#! /opt/homebrew/bin/python

import glob
import subprocess


def main():
    score = 0
    for f in glob.glob("ahc026/A/in/*.txt"):
        res = subprocess.run(f"ahc026/A/main < {f} > {f.replace('in', 'out')}", shell=True, stderr=subprocess.PIPE)
        stderr = res.stderr.decode("utf-8")
        score += int(stderr.split("\n")[1].split(" ")[-1])
    print(score)


if __name__ == "__main__":
    main()
