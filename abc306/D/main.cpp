#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vl x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    vvl dp(n + 1, vl(2, 0));
    dp[0][x[0]] = max(0, y[0]);
    if (x[0] == 0)
        dp[0][1] = -1e18;

    rep2(i, 1, n)
    {
        if (x[i] == 0)
        {
            dp[i][0] = max(max(dp[i - 1][0] + y[i], dp[i - 1][1] + y[i]), dp[i - 1][0]);
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            dp[i][1] = max(dp[i - 1][0] + y[i], dp[i - 1][1]);
            dp[i][0] = dp[i - 1][0];
        }
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
}
