#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl a(N);
    cin >> a;
    vector dp(N + 1, vector(N + 1, vector(N + 1, vector(N + 1, mint(0)))));
    rep(k, N + 1) { dp[0][0][k][0] = 1; }
    rep(i, N) {
        dp[i + 1] = dp[i];
        rep(j, N) rep(k, 1, N + 1) rep(l, k + 1) { dp[i + 1][j + 1][k][(l + a[i]) % k] += dp[i][j][k][l]; }
    }
    mint ans = 0;
    rep(j, N) { ans += dp[N][j + 1][j + 1][0]; }
    cout << ans.val() << endl;
}
