#include "../../lib.hpp"

// #define MOD 1000000007
#define MOD 998244353

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    vector<vector<ll>> dp(3001, vector<ll>(3001, 0));
    rep(i, n)
    {
        if (i == 0)
        {
            for (int j = a[i]; j <= b[i]; j++)
            {
                dp[i + 1][j] = 1;
            }
        }
        for (int j = a[i]; j <= b[i]; j++)
        {
            if (j == a[i])
            {
                for (int k = a[i - 1]; k <= j; k++)
                {
                    dp[i + 1][j] += dp[i][k];
                }
                dp[i + 1][j] %= MOD;
            }
            else
            {
                dp[i + 1][j] = dp[i + 1][j - 1] + dp[i][j];
                dp[i + 1][j] %= MOD;
            }
        }
    }
    ll ans = 0;
    for (int i = a[n - 1]; i <= b[n - 1]; i++)
    {
        ans += dp[n][i];
    }
    ans %= MOD;
    cout << ans << endl;
}
