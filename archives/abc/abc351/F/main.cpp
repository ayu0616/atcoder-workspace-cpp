#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

#include <atcoder/lazysegtree.hpp>
#include <atcoder/segtree.hpp>

using S = ll;
using F = ll;
S op(S l, S r) { return l + r; }
S e() { return S(); }
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return F(); }

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;

    vl sorted_A = A;
    sort(all(sorted_A));
    map<ll, ll> mp;
    ll cnt = 0;
    rep(i, N) {
        if (mp.find(sorted_A[i]) == mp.end()) {
            mp[sorted_A[i]] = cnt++;
        }
    }

    ll ans = 0;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(N + 10);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg1(N + 10);
    rep(i, N) {
        seg.apply(mp[A[i]], 1);
        seg1.apply(mp[A[i]], A[i]);
    }
    rep(i, N) {
        ll a = A[i];
        seg.apply(mp[a], -1);
        seg1.apply(mp[a], -a);
        ll sum = seg.prod(mp[a], N + 10);
        ll sum1 = seg1.prod(mp[a], N + 10);
        ans += sum1 - sum * a;
    }
    cout << ans << endl;
}
