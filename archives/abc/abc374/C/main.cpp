#include <numeric>
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
    vl K(N);
    cin >> K;
    ll k_sum = accumulate(all(K), 0LL);
    ll ans = LL_INF;
    for (ll S = 0; S < 1LL << N; S++) {
        ll sum = 0;
        rep(i, N) {
            if (S >> i & 1) {
                sum += K[i];
            }
        }
        ll a = max(sum, k_sum - sum);
        ans = min(ans, a);
    }
    cout << ans << endl;
}
