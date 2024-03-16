#include <numeric>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct State {
    ll total_value;
    ll prev_col;

    State() : total_value(LL_INF), prev_col(0) {}
};

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl C(N), V(N);
    rep(i, N) cin >> C[i] >> V[i];
    vector<vector<vector<State>>> dp(N + 1, vector<vector<State>>(K + 1, vector<State>(2)));
    dp[0][0][0].total_value = 0;
    dp[0][0][1].total_value = 0;
    rep(i, N) {
        rep(k, K) {
            ll false_min = LL_INF;
            if (C[i] != dp[i][k][0].prev_col) {
                false_min = min(false_min, dp[i][k][0].total_value);
            }
            if (C[i] != dp[i][k][1].prev_col) {
                false_min = min(false_min, dp[i][k][1].total_value);
            }
            dp[i + 1][k][0] = dp[i][k][0];
            if (dp[i + 1][k][0].total_value > false_min) {
                dp[i + 1][k][0].total_value = false_min;
                dp[i + 1][k][0].prev_col = C[i];
            }

            ll true_min = LL_INF;
            ll prev_col = 0;
            if (true_min > dp[i][k][0].total_value + V[i]) {
                true_min = dp[i][k][0].total_value + V[i];
                prev_col = dp[i][k][0].prev_col;
            }
            if (true_min > dp[i][k][1].total_value + V[i]) {
                true_min = dp[i][k][1].total_value + V[i];
                prev_col = dp[i][k][1].prev_col;
            }
            dp[i + 1][k + 1][1] = dp[i][k][1];
            if (dp[i + 1][k + 1][1].total_value > true_min) {
                dp[i + 1][k + 1][1].total_value = true_min;
                dp[i + 1][k + 1][1].prev_col = prev_col;
            }
        }
    }
    ll ans = accumulate(all(V), 0LL);
    ll mi = min(dp[N][K][0].total_value, dp[N][K][1].total_value);
    ans -= mi;
    if (mi == LL_INF) ans = -1;
    cout << ans << endl;
}
