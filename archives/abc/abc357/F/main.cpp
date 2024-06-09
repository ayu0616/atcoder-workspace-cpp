#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

#include <atcoder/lazysegtree.hpp>

namespace seg {

struct S {
    mint a, b, ab;
    ll size;
};
struct F {
    mint a, b;
};
S op(S a, S b) { return {a.a + b.a, a.b + b.b, a.ab + b.ab, a.size + b.size}; }
S e() { return {0, 0, 0, 0}; }
S mapping(F f, S x) { return {x.a + f.a * x.size, x.b + f.b * x.size, x.ab + f.a * x.b + f.b * x.a + f.a * f.b * x.size, x.size}; }
F composition(F f, F g) { return {f.a + g.a, f.b + g.b}; }
F id() { return {0, 0}; }
using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

}  // namespace seg

struct Query {
    ll t, l, r, x;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N >> Q;
    vl A(N), B(N);
    cin >> A >> B;
    seg::segtree seg(N);
    rep(i, N) { seg.set(i, {A[i], B[i], A[i] * B[i], 1}); }
    vector<Query> queries(Q);
    rep(i, Q) {
        cin >> queries[i].t >> queries[i].l >> queries[i].r;
        queries[i].l--;
        if (queries[i].t != 3) {
            cin >> queries[i].x;
        }
    }

    for (auto &q : queries) {
        auto [t, l, r, x] = q;
        switch (t) {
            case 1: {
                seg.apply(l, r, {x, 0});
                break;
            }
            case 2: {
                seg.apply(l, r, {0, x});
                break;
            }
            case 3: {
                cout << seg.prod(l, r).ab << endl;
                break;
            }
            default: {
                exit(1);
            }
        }
    }
}
