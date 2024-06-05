#include <cassert>
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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<vector<mint>> dp(K + 1, vector<mint>(N + 1, 0));
    mint p = mint(M).inv();
    dp[0][0] = 1;
    rep(k, K) {
        rep(i, N) {
            assert(i<N);
            rep(m, M) {
                ll next = i + (m + 1);
                if (next > N) {
                    next = N - (next - N);
                }
                dp[k + 1][next] += dp[k][i] * p;
            }
        }
    }
    mint ans = 0;
    rep(k, K + 1) {
        ans += dp[k][N];
    }
    cout << ans << endl;
}
