#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/segtree.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using S = ll;
S op(S a, S b) { return a + b; }
S e() { return 0; }
using segtree = atcoder::segtree<S, op, e>;

ll find_over_one(segtree& seg, ll l, ll r) {
    ll l0 = l;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll sum = seg.prod(l0, m);
        if (sum == m - l0) {
            l = m;
        } else {
            r = m;
        }
    }
    return l;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N;
    vl A(N), B(N);
    cin >> A >> B >> Q;
    segtree seg_a(N), seg_b(N);
    rep(i, N) {
        seg_a.set(i, A[i]);
        seg_b.set(i, B[i]);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            ll i, x;
            cin >> i >> x;
            i--;
            A[i] = x;
            seg_a.set(i, x);
        } else if (t == 2) {
            ll i, x;
            cin >> i >> x;
            i--;
            B[i] = x;
            seg_b.set(i, x);
        } else {
            ll l, r;
            cin >> l >> r;
            l--;
            ll v = 0;
            v += A[l];
            l++;
            while (l < r) {
                int i = find_over_one(seg_b, l, r);
                v += seg_a.prod(l, i);
                if (i == r) break;
                v = max(v + A[i], v * B[i]);
                l = i+1;
            }
            cout << v << endl;
        }
    }
}
