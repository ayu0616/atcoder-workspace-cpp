n, k = map(int, input().split())
a = list(map(int, input().split()))

b = [0] * n
under = 1
upper = n * (n + 1) // 2
for i in range(n):
    sm = list(filter(lambda x: x < a[0], a))
    lg = list(filter(lambda x: x > a[0], a))
    sm_siz = len(sm)
    lg_siz = len(lg)
    eq_siz = len(a) * (len(a) + 1) // 2 - (sm_siz) - (lg_siz)

    if under + sm_siz <= k <= upper - lg_siz:
        b[i] = a[0]
        a.remove(a[0])
        under += sm_siz
        upper -= lg_siz
    elif k <= under + sm_siz:
        resid = k - under
        sm_item = sorted(sm)[resid - 1]
        b[i:] = list(reversed(a[: a.index(sm_item) + 1])) + a[a.index(sm_item) + 1 :]
        break
    else:
        resid = upper - k
        lg_item = sorted(lg)[resid - 1]
        b[i:] = list(reversed(a[: a.index(lg_item) + 1])) + a[a.index(lg_item) + 1 :]
        break

print(*b)
