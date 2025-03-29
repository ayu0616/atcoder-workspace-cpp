#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/lazysegtree>

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using S = ll;
using F = vl;
S op(S a, S b) { return a + b; }
S e() { return 0; }
S mapping(F f, S x) {
    ll res = x;
    rep(i, f.size()) { if(res>=f[i])res++; }
    return res;
}
F composition(F f, F g) { rep(i, g.size()) { f.push_back(g[i]); } return f; }
F id() { return {}; }

using segtree = atcoder::lazy_segtree<S, op, e, F, mapping, composition, id>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl P(N);
    cin >> P;
    rep(i, N) { P[i]--; }
    segtree seg(N);
    rep(i, N) {
        ll p = P[i];
        seg.apply(0, i, {p});
        seg.set(i, p);
    }
    vi ans(N, -1);
    rep(i, N) { ans[seg.get(i)] = i + 1; }
    rep(i,N){
        if(ans[i]==-1) ans[i]=i+1;
    }
    cout << ans << endl;
}
