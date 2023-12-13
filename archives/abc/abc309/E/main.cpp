#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vi g(n);
    rep2(i, 1, n)
    {
        int p;
        cin >> p;
        g[i] = p - 1;
    }
    vi d(n, -1);
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        chmax(d[x - 1], y);
    }
    int ans = 0;
    rep(i, n)
    {
        if (i > 0)
        {
            chmax(d[i], d[g[i]] - 1);
        }
        if (d[i] >= 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
}