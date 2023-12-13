#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vl x(n), y(n), z(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i] >> z[i];
    }
    ll sum_z = 0;
    rep(i, n) sum_z += z[i];
    vl dp(sum_z + 1, 1e18);
    dp[0] = 0;
    rep(i, n)
    {
        ll w = max(0, (y[i] - x[i]) / 2 + 1);
        for (int j = sum_z; j >= z[i]; j--)
        {
            chmin(dp[j], dp[j - z[i]] + w);
        }
    }
    ll ans = 1e18;
    rep2(i, sum_z/2+1, sum_z+1)
    {
        chmin(ans, dp[i]);
    }
    cout << ans << endl;
}
