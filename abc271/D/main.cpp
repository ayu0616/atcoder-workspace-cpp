#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    rep(i, n + 1) rep(j, s + 1)
    {
        if (i == 0 && j == 0)
        {
            dp[i][j] = true;
            continue;
        }
        if (i == 0)
        {
            continue;
        }
        if (j + a[i - 1] <= s && dp[i - 1][j])
        {
            dp[i][j + a[i - 1]] = true;
        }
        if (j + b[i - 1] <= s && dp[i - 1][j])
        {
            dp[i][j + b[i - 1]] = true;
        }
    }
    // rep(i, n + 1) rep(j, s + 1) cout << dp[i][j] << " \n"[j == s];

    if (dp[n][s])
    {
        cout << "Yes" << endl;
        vector<char> ans(n);
        for (int i = n; i > 0; i--)
        {
            if (s - a[i - 1] >= 0 && dp[i - 1][s - a[i - 1]])
            {
                ans[i - 1] = 'H';
                s -= a[i - 1];
                continue;
            }
            if (s - b[i - 1] >= 0 && dp[i - 1][s - b[i - 1]])
            {
                ans[i - 1] = 'T';
                s -= b[i - 1];
                continue;
            }
        }
        rep(i, n) cout << ans[i];
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
