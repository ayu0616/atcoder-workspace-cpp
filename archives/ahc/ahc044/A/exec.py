import subprocess
import os
import concurrent.futures

os.chdir(os.path.dirname(os.path.abspath(__file__)))


def execute(seed: int):
    subprocess.run(
        f"./main < in/{seed:04d}.txt > out/{seed:04d}.txt", shell=True, check=True
    )


def execute_all():
    with concurrent.futures.ThreadPoolExecutor(max_workers=os.cpu_count()) as executor:
        executor.map(execute, range(500))


def score(seed: int):
    input = open(f"in/{seed:04d}.txt").read().strip().split("\n")
    output = open(f"out/{seed:04d}.txt").read().strip().split("\n")

    N, L = map(int, input[0].split())
    T = list(map(int, input[1].split()))
    assert len(T) == N
    assert sum(T) == L

    ans = [list(map(int, line.split())) for line in output]
    assert len(ans) == N
    assert all(len(a) == 2 for a in ans)

    cnt = [0] * N
    cur = 0
    for _ in range(L):
        cnt[cur] += 1
        cur = ans[cur][1 - (cnt[cur] % 2)]
    e = 0
    for i in range(N):
        e += abs(T[i] - cnt[i])
    return 10**6 - e


def score_all() -> list[int]:
    scores = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=os.cpu_count()) as executor:
        scores = list(executor.map(score, range(500)))
    return scores


if __name__ == "__main__":
    execute_all()

    scores = score_all()
    for i, s in enumerate(scores):
        print(f"{i:04d}: {s}")
    print(sum(scores))
