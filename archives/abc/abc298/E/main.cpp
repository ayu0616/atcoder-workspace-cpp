#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int N;

void solve(vector<vector<mint>>& dp, int init, int dice_max) {
    dp[init][0] = 1;
    for (int i = init; i < N; i++) {
        for (int j = 1; j <= dice_max; j++) {
            rep(t, N) {
                int next = min(N, i + j);
                dp[next][t + 1] += dp[i][t] / dice_max;
            }
        }
    }
}

int main() {
    cout << fixed << setprecision(18);
    int A, B, P, Q;
    cin >> N >> A >> B >> P >> Q;
    vector<vector<mint>> dp_t(N + 1, vector<mint>(N + 1, 0));
    vector<vector<mint>> dp_a(N + 1, vector<mint>(N + 1, 0));
    solve(dp_t, A, P);
    solve(dp_a, B, Q);
    vector<mint> sum_t(N + 1, 0);
    rep(i, N) { sum_t[i+1] = sum_t[i] + dp_t[N][i + 1]; }
    mint ans = 0;
    rep(i, N) { ans += dp_a[N][i] * sum_t[i]; }
    cout << ans << endl;
}
