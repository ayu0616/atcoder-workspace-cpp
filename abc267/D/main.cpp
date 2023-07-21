#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n, m;
ll a[2010], dp[2010][2010];

int main()
{
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    rep(i, 2010) rep(j, 2010) dp[i][j] = -1e18;

    rep(i, n) dp[i][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= min(i + 1, m); j++)
        {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + j * a[i]);
        }
    }
    cout << dp[n - 1][m] << endl;
}
