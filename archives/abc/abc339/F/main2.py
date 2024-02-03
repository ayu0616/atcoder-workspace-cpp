from collections import Counter

N = int(input())
A: list[int] = []
for i in range(N):
    A.append(int(input()))

counter = Counter(A)

ans = 0

for i in range(len(A)):
    ai = A[i]
    ans += counter[ai * ai]
    for j in range(i + 1, len(A)):
        aj = A[j]
        aij = ai * aj
        ans += counter[aij] * 2

print(ans)
