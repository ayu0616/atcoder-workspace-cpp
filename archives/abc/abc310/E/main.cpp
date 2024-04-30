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
    string S;
    cin >> N >> S;
    vvl dp(N + 1, vl(2, 0));
    rep(i, N) {
        dp[i + 1][S[i] - '0'] = 1;
        if (S[i] == '0') {
            dp[i + 1][1] += dp[i][0] + dp[i][1];
        } else {
            dp[i + 1][0] += dp[i][1];
            dp[i + 1][1] += dp[i][0];
        }
    }
    ll ans = 0;
    rep(i, N) { ans += dp[i + 1][1]; }
    cout << ans << endl;
}
