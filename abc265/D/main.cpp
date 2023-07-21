#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, P, Q, R, v, p, q, r, sy, sz, sw, y, z, w;
ll a[200000 + 10];
string ans;

ll search(ll x, ll from, ll to)
{
    ll mid = (from + to) / 2;
    if (a[mid] >= x)
    {
        if (mid == from)
        {
            if (a[mid] == x)
                return mid;
            return -1;
        }
        return search(x, from, mid);
    }
    else
    {
        if (mid == to)
        {
            if (a[mid] == x)
                return mid;
            return -1;
        }
        return search(x, mid + 1, to);
    }
}

int main()
{
    cin >> n >> P >> Q >> R;
    a[0] = 0;
    rep(i, n)
    {
        cin >> v;
        a[i + 1] = a[i] + v;
    }

    ans = "No";

    for (ll x = 0; x <= n - 3; x++)
    {
        sy = a[x] + P;
        y = search(sy, x + 1, n - 2);
        if (y == -1)
            continue;
        sz = a[y] + Q;
        z = search(sz, y + 1, n - 1);
        if (z == -1)
            continue;
        sw = a[z] + R;
        w = search(sw, z + 1, n);
        if (w == -1)
            continue;
        ans = "Yes";
        break;
    }
    cout << ans << endl;
}