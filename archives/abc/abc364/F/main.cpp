#include <vector>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/lazysegtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct S {
    ll val, size;
};
using F = ll;
const F ID = LL_INF;
S op(S a, S b) { return {a.val + b.val, a.size + b.size}; }
S e() { return {0, 0}; }
S mapping(F f, S x) {
    if (f != ID) return {x.size * f, x.size};
    return x;
}
F composition(F f, F g) { return f == ID ? g : f; }
F id() { return ID; }

struct Query {
    ll L, R, C;

    bool operator<(const Query& other) const { return C < other.C; }
};

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N >> Q;
    vector<Query> queries(Q);
    rep(i, Q) {
        ll L, R, C;
        cin >> L >> R >> C;
        queries[i] = {L, R, C};
    }
    sort(all(queries));
    vector<S> v(N, {1, 1});
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
    ll ans = 0;
    for (auto [L, R, C] : queries) {
        ll cnt = seg.prod(L - 1, R - 1).val;
        cnt++;
        ans += cnt * C;
        seg.apply(L - 1, R - 1, 0);
    }
    if (seg.prod(0, N - 1).val > 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}
