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
    ll ans = 0;
    rep(i, 32) {
        vi v(N);
        rep(j, N) { v[j] = (A[j] >> i) & 1; }
        ll dp[N + 10][2];
        rep(j, N + 10) rep(k, 2) dp[j][k] = 0;
        ll cnt = 0;
        rep(j, 2, N + 1) {
            dp[j][v[j - 2] ^ v[j - 1]] += 1;
            if (v[j-1] == 0) {
                dp[j][0] += dp[j - 1][0];
                dp[j][1] += dp[j - 1][1];
            } else {
                dp[j][0] += dp[j - 1][1];
                dp[j][1] += dp[j - 1][0];
            }
        }
        rep(j, N + 1) { cnt += dp[j][1]; }
        ans += (1LL << i) * cnt;
    }
    cout << ans << endl;
}
