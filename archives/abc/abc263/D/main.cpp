#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n, l, r;
    cin >> n >> l >> r;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<vector<ll>> dp(n, vector<ll>(3, 1e18));
    rep(i, n)
    {
        if (i == 0)
        {
            dp[i][0] = l;
            dp[i][1] = a[i];
            dp[i][2] = r;
        }
        else
        {
            dp[i][0] = dp[i - 1][0] + l;
            dp[i][1] = min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
            dp[i][2] = min(dp[i - 1][1] + r, dp[i - 1][2] + r);
        }
    }
    ll ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    cout << ans << endl;
}
