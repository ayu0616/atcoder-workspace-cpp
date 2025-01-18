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
    ll R;
    cin >> R;
    ll ans = 4 * R - 3;
    ll R2 = 2 * R;
    for (ll x = 3; x <= R2; x += 2) {
        ll y = sqrt(R2 * R2 - x * x);
        ans += 4 * ((y - 1) / 2);
    }
    cout << ans << endl;
}
