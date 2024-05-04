#include <numeric>
#include <queue>
#include <set>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Coupon {
    ll l, d;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    multiset<ll> p;
    ll ans = 0;
    rep(i, 0, N) {
        ll a;
        cin >> a;
        p.insert(a);
        ans += a;
    }
    vector<Coupon> coupons(M);
    {
        vl l(M), d(M);
        cin >> l >> d;
        rep(i, M) coupons[i] = {l[i], d[i]};
    }
    sort(all(coupons), [](const Coupon &a, const Coupon &b) { return a.d > b.d; });
    for (auto coupon : coupons) {
        ll l = coupon.l;
        ll d = coupon.d;
        auto it = p.lower_bound(l);
        if (it == p.end()) continue;
        ans -= d;
        p.erase(it);
    }
    cout << ans << endl;
}
