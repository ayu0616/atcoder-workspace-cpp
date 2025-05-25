#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

void solve() {
    ll N;
    cin >> N;
    vl A(2 * N);
    cin >> A;
    map<ll, ll> dp;
    dp[0] = 0;
    rep(i, 2 * N) {
        map<ll, ll> new_dp;
        for (auto [x, y] : dp) {
            if (x < 2 * N - i) {
                new_dp[x + 1] = max(new_dp[x + 1], y + A[i]);
            }
            if (x > 0) {
                new_dp[x - 1] = max(new_dp[x - 1], y);
            }
        }
        map<ll, ll> new_dp2;
        ll max_y = 0;
        for (auto [x, y] : new_dp) {
            if (y > max_y) {
                max_y = y;
                new_dp2[x] = y;
            }
        }
        dp = new_dp2;
    }
    cout << dp[0] << endl;
}

int main() {
    cout << fixed << setprecision(18);
    ll T;
    cin >> T;
    while (T--) {
        solve();
    }
}
