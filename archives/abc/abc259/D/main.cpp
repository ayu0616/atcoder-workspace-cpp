#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<vector<ll>> c(n, vector<ll>(3));
    rep(i, n) cin >> c[i][0] >> c[i][1] >> c[i][2];
    ll cs, ct;
    if (powl(sx - c[n - 1][0], 2) + powl(sy - c[n - 1][1], 2) == powl(c[n - 1][2], 2))
        cs = n - 1;
    if (powl(tx - c[n - 1][0], 2) + powl(ty - c[n - 1][1], 2) == powl(c[n - 1][2], 2))
        ct = n - 1;
    UnionFind uf(n);
    for (int i = 0; i < n - 1; i++)
    {
        if (powl(sx - c[i][0], 2) + powl(sy - c[i][1], 2) == powl(c[i][2], 2))
            cs = i;
        if (powl(tx - c[i][0], 2) + powl(ty - c[i][1], 2) == powl(c[i][2], 2))
            ct = i;
        for (int j = i + 1; j < n; j++)
        {
            ll c_dist = powl(c[i][0] - c[j][0], 2) + powl(c[i][1] - c[j][1], 2);
            ll r_sum = powl(c[i][2] + c[j][2], 2);
            ll r_diff = powl(c[i][2] - c[j][2], 2);
            if (c_dist <= r_sum && c_dist >= r_diff)
            {
                uf.unite(i, j);
            }
        }
    }
    string ans = (uf.same(cs, ct)) ? "Yes" : "No";
    cout << ans << endl;
}
