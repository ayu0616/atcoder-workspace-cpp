#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    vector dp(N + 1, vector(N + 1, -LL_INF));
    dp[1][0] = 0;
    rep(i, 1, N) {
        rep(j, 0, i) {
            chmax(dp[i + 1][0], dp[i][j]);
            chmax(dp[i + 1][j + 1], dp[i][j] + A[j / 2]);
        }
    }
    ll ans = 0;
    rep(i, 0, N) {
        chmax(ans, dp[N][i] );
    }
    cout << ans << endl;
}
