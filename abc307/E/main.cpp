#include "../../lib.hpp"

const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

using mint = static_modint<MOD>;

int n, m;
vector<vector<mint>> dp;

int main()
{
    cin >> n >> m;
    dp.resize(n, vector<mint>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = m;
    rep(i, n - 1)
    {
        dp[i + 1][0] = dp[i][0] * (m - 2) + dp[i][1] * (m - 1);
        dp[i + 1][1] = dp[i][0];
    }
    cout << dp[n - 1][0] << endl;
}
