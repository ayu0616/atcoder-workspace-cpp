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
    ll N, W;
    cin >> N >> W;
    ll w[N], v[N];
    rep(i, N) { cin >> w[i] >> v[i]; }
    ll dp[N + 1][W + 1];
    rep(i, N + 1) {
        rep(j, W + 1) { dp[i][j] = 0; }
    }
    rep(i, N) {
        rep(j, W) {
            for (ll k = 1; j + k * w[i] <= W; k++) {
                dp[i + 1][j + k * w[i]] = max(dp[i + 1][j + k * w[i]], dp[i][j] + k * v[i] - k * k);
            }
        }
    }

    cout << dp[N][W] << endl;
}
