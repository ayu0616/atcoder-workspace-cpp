#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/lazysegtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using S = pll;
using F = pll;
S op(S a, S b) { return min(a, b); }
S e() { return {LL_INF, -1}; }
S mapping(F f, S x) { return min(f, x); }
F composition(F f, F g) { return min(f, g); }
F id() { return {LL_INF, -1}; }

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N >> Q;
    vl c_li(Q, LL_INF);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
    rep(i, Q) {
        ll L, R, C;
        cin >> L >> R >> C;
        seg.apply(L - 1, R, {C, N + i});
        c_li[i] = C;
    }
    ll ans = 0;
    vl used(Q, 0);
    rep(i, N) {
        auto [v, j] = seg.get(i);
        if (v == LL_INF) {
            cout << -1 << endl;
            return 0;
        } else {
            ans += v;
            used[j - N]++;
        }
    }
    rep(i, Q) {
        if (used[i]<=1) {
            ans += c_li[i] * (2 - used[i]);
        }
    }
    cout << ans << endl;
}
