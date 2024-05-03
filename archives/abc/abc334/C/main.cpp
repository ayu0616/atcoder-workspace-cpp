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
    vl A(K);
    cin >> A;
    if (K % 2 == 0) {
        ll ans = 0;
        rep(i, K / 2) { ans += A[2 * i + 1] - A[2 * i]; }
        cout << ans << endl;
    } else {
        vl B1(K / 2), B2(K / 2);
        rep(i, K / 2) {
            B1[i] = A[2 * i + 1] - A[2 * i];
            B2[i] = A[2 * i + 2] - A[2 * i + 1];
        }
        vl B1_sum(K / 2 + 1), B2_sum(K / 2 + 1);
        rep(i, K / 2) {
            B1_sum[i + 1] = B1_sum[i] + B1[i];
            B2_sum[i + 1] = B2_sum[i] + B2[i];
        }
        ll ans = LL_INF;
        rep(i, K / 2 + 1) {
            ll tmp = B1_sum[i] + B2_sum[K / 2] - B2_sum[i];
            chmin(ans, tmp);
        }
        cout << ans << endl;
    }
}
