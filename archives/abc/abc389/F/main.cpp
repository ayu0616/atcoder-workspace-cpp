#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/lazysegtree.hpp>

#include "../../lib.hpp"

using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }
S mapping(ll f, S x) { return f + x; }
ll composition(ll f, ll g) { return f + g; }
ll id() { return 0; }

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr int MAX = 5 * 100000 + 10;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    atcoder::lazy_segtree<S, op, e, ll, mapping, composition, id> seg(MAX);
    rep(i, MAX) { seg.set(i, i); }
    rep(N) {
        ll l, r;
        cin >> l >> r;
        ll lleft = -1;
        ll lright = MAX;
        while (lright - lleft > 1) {
            ll mid = (lleft + lright) / 2;
            if (seg.get(mid) >= l) {
                lright = mid;
            } else {
                lleft = mid;
            }
        }
        ll rleft = -1;
        ll rright = MAX;
        while (rright - rleft > 1) {
            ll mid = (rleft + rright) / 2;
            if (seg.get(mid) > r) {
                rright = mid;
            } else {
                rleft = mid;
            }
        }
        seg.apply(lright, rright, 1);
    }
    ll Q;
    cin >> Q;
    rep(Q) {
        ll x;
        cin >> x;
        cout << seg.get(x) << endl;
    }
}
