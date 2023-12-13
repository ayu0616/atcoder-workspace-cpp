#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    vvl A(N, vl(N));
    rep(i, N) rep(j, N) cin >> A[i][j];

    vvl dp(1 << N, vl(N, LLONG_MAX / 2));
    dp[0][0] = 0;
    rep(S, 1 << N)
    {
        rep(i, N)
        {
            rep(j, N)
            {
                if (S >> j & 1)
                    continue;
                chmin(dp[S | 1 << j][j], dp[S][i] + A[i][j]);
            }
        }
    }

    cout << dp[(1 << N) - 1][0] << endl;
}
