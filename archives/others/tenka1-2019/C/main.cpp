#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    map<char, int> col;
    col['.'] = 0;
    col['#'] = 1;
    int N;
    string S;
    cin >> N >> S;

    vvi dp(N, vi(2, 0));
    dp[0][1 - col[S[0]]] = 1;
    rep(i, N - 1)
    {
        if (S[i + 1] == '.')
        {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = min(dp[i][0] + 1, dp[i][1] + 1);
        }
        else
        {
            dp[i + 1][0] = dp[i][0] + 1;
            dp[i + 1][1] = min(dp[i][0], dp[i][1]);
        }
    }
    cout << min(dp[N - 1][0], dp[N - 1][1]) << endl;
}
