#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n), b(n), c(n), d(n);
    rep(i, n) cin >> a[i] >> b[i] >> c[i] >> d[i];
    vvi grid(100, vi(100, 0));
    rep(i, n)
    {
        for (int j = a[i]; j < b[i]; j++)
            for (int k = c[i]; k < d[i]; k++)
                grid[j][k] = 1;
    }
    int ans = 0;
    rep(i, 100) rep(j, 100) if (grid[i][j]) ans++;
    cout << ans << endl;
}
