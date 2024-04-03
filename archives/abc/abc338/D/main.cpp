#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/lazysegtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using S = ll;
S op(S a, S b) { return min(a, b); }
S e() { return LL_INF; }
using F = ll;
S mapping(F f, S x) { return f + x; }
F composition(F f, F g) { return f + g; }
F id() { return 0; }

int main() {
    cout << fixed << setprecision(18);
    int N, M;
    cin >> N >> M;
    vi X(M);
    cin >> X;
    rep(i, M) X[i]--;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(N);
    rep(i, N) seg.set(i, 0);
    ll ans = 0;
    rep(i, M - 1) {
        int x = X[i];
        int y = X[i + 1];
        if (x > y) swap(x, y);
        int right_cost = y - x;
        int left_cost = N - right_cost;
        ans += min(right_cost, left_cost);
        if (right_cost < left_cost) {
            seg.apply(x, y, left_cost - right_cost);
        } else if (right_cost > left_cost) {
            seg.apply(0, x, right_cost - left_cost);
            seg.apply(y, N, right_cost - left_cost);
        }
    }
    // rep(i, N) { cerr << i << " " << seg.get(i) << endl; }
    ans += seg.all_prod();
    cout << ans << endl;
}
