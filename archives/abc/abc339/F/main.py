from collections import Counter

N = int(input())
A: list[int] = []
for i in range(N):
    A.append(int(input()))

P = 12345678901234567890
A = [a % P for a in A]

counter = Counter(A)

ans = 0


for i in range(len(A)):
    ai = A[i]
    for j in range(i, len(A)):
        aj = A[j]
        aij = (ai * aj) % P
        ans += counter[aij]
        if i != j:
            ans += counter[aij]

print(ans)
