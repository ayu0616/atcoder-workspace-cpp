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
    ll N, M;
    cin >> N >> M;
    mint N_mint = N;
    mint ans = 0;
    for (ll i = 0; i <= 60; i++) {
        if (M >> i & 1) {
            ll a = (N + 1) / (1LL << i);
            ll b = (N + 1) % (1LL << i);
            ans += mint(a/2)*mint(1LL << i);
            if (a % 2 == 1) {
                ans += mint(b);
            }
        }
    }
    cout << ans << endl;
}
