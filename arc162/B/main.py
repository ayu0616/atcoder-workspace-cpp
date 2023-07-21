import heapq

n = int(input())
p = list(map(int, input().split()))


class State:
    def __init__(self, m, p, i, j, prev):
        self.m = m
        self.p = p
        self.dist = self.__calc_dist()
        self.i = i
        self.j = j
        self.prev = prev

    def __calc_dist(self):
        d = 0
        for i, v in enumerate(self.p):
            d += abs(i + 1 - v)
        return d

    def __lt__(self, other):
        return self.dist + self.m < other.dist + other.m


def sorting(p, i, j):
    q = p[:i] + p[i + 2 :]
    new_p = q[:j] + p[i : i + 2] + q[j:]
    return new_p


init_s = State(0, p, -1, -1, None)
q = [init_s]

while len(q) > 0:
    s = heapq.heappop(q)
    if s.dist > 2000:
        print("No")
        break
    if s.dist == 0:
        print("Yes")
        print(s.m)
        prevs = []
        while s.prev is not None:
            prevs.append(s)
            s = s.prev
        prevs.reverse()
        for s in prevs:
            print(s.i + 1, s.j)
        break
    for i in range(n - 1):
        for j in range(n - 1):
            s2 = sorting(s.p, i, j)
            s3 = State(s.m + 1, s2, i, j, s)
            heapq.heappush(q, s3)
