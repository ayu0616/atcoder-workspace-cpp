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
    ll N, K;
    cin >> N >> K;
    vl P(N);
    cin >> P;
    rep(i, N) P[i]--;

    vvl dp(62, vl(10010));
    rep(i, N) dp[0][i] = P[P[i]];
    rep(i, 61) {
        rep(j, N) { dp[i + 1][j] = dp[i][dp[i][j]]; }
    }

    vl ans(N);
    rep(i, N) {
        ll now = P[i];
        ll k = K;
        int j = 0;
        while (k > 0) {
            if (k & 1) {
                now = dp[j][now];
            }
            j++;
            k >>= 1;
        }
        ans[now] = i;
    }

    rep(i, N) ans[i]++;
    cout << ans << endl;
}
