#include "hassaku/union-find.hpp"
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, H, M;
    cin >> N >> H >> M;
    vl A(N), B(N);
    rep(i, N) { cin >> A[i] >> B[i]; }
    ll l = 0, r = N + 1;

    auto check = [&](ll mid) -> bool {
        vvi dp(mid + 1, vi(H + 1, INT_INF));
        dp[0][0] = 0;
        rep(i, mid) {
            rep(j, H+1) {
                if (j + A[i] <= H) {
                    dp[i + 1][j + A[i]] = min(dp[i + 1][j + A[i]], dp[i][j]);
                }
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + B[i]);
            }
        }
        bool res = *min_element(all(dp[mid])) <= M;
        return res;
    };

    while (r - l > 1) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l << endl;
}