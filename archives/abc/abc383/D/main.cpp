#include <algorithm>
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
    ll ans = 0;

    ll n = sqrt(N);
    auto primes = create_primes(n);
    set<pll> st;
    rep(i, primes.size()) {
        ll p = primes[i];
        ll l = i, r = primes.size();
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (p * p * primes[m] * primes[m] <= N) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l == i) break;
        ans += l - i;
    }
    for (auto p : primes) {
        if (powl(p, 8) > N) break;
        ans++;
    }
    cout << ans << endl;
}
