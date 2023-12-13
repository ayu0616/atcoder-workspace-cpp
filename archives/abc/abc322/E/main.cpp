#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, K, P;
    cin >> N >> K >> P;
    vl C(N);
    vvl A(N, vl(K));
    rep(i, N)
    {
        cin >> C[i];
        rep(j, K) cin >> A[i][j];
    }
    vvl dp(N + 1, vl(powl(P + 1, K), 1e18));
    dp[0][0] = 0;
    rep(i, N)
    {
        rep(j, powl(P + 1, K))
        {
            ll next = j;
            rep(k, K) next += powl(P + 1, k) * A[i][k];
            chmin(dp[i + 1][next], dp[i][j] + C[i]);
        }
    }
    cout << (dp[N][powl(P + 1, K) - 1] == 1e18 ? -1 : dp[N][powl(P + 1, K) - 1]) << endl;
}
