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
    ll N, Q;
    cin >> N >> Q;
    vl a(N);
    cin >> a;
    sort(all(a));
    while (Q--) {
        ll b, k;
        cin >> b >> k;
        ll l = -1;
        ll r = 1e9;
        while (r - l > 1) {
            ll m = (l + r) / 2;
            ll l_dist = lower_bound(all(a), b - m) - a.begin();
            ll r_dist = upper_bound(all(a), b + m) - a.begin();
            if (r_dist - l_dist >= k) {
                r = m;
            } else {
                l = m;
            }
        }
        cout << r << endl;
    }
}
