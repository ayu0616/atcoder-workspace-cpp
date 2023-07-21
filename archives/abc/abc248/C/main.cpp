#include "../../lib.hpp"

// #define MOD 1000000007
#define MOD 998244353

int main()
{
    int n, m, k;
    ll dp[51][2501];
    cin >> n >> m >> k;
    rep(i, 51) rep(j, 2501) dp[i][j] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int a = 1; a <= m; a++)
        {
            if (i == 1)
            {
                dp[i][a] = 1;
                continue;
            }
            for (int j = 1; j <= k - a; j++)
            {
                dp[i][j + a] += dp[i - 1][j];
                dp[i][j + a] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
}
