#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll max_vec(vector<ll> v)
{
    ll max = 0;
    for (auto i : v)
    {
        if (i > max)
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    map<int, ll> bonus;
    rep(i, m)
    {
        int c;
        ll y;
        cin >> c >> y;
        bonus[c] = y;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[1][1] = x[0] + bonus[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
            {
                dp[i][j] = max_vec(dp[i - 1]);
            }
            else
            {
                if (dp[i - 1][j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + x[i - 1] + bonus[j];
                }
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << max_vec(dp[n]) << endl;
}
