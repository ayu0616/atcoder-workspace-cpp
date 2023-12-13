#include "../../lib.hpp"

const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    string s;
    cin >> s;
    vector<vector<mint>> dp(s.size(), vector<mint>(2));
    if (s[0] == '(' || s[0] == '?')
    {
        dp[0][0] = 1;
    }
    else
    {
        dp[0][0] = 0;
    }
    dp[0][1] = 0;
    rep(i, s.size() - 1)
    {
        if (s[i+1] == '(')
        {
            dp[i + 1][0] = dp[i][0] + dp[i][1];
        }
        else if (s[i+1] == ')')
        {
            dp[i + 1][1] = dp[i][0] + dp[i][1];
        }
        else
        {
            dp[i + 1][0] = dp[i][0] + dp[i][1];
            dp[i + 1][1] = dp[i][0] + dp[i][1];
        }
    }
    cout << dp[s.size() - 1][1] << endl;
}
