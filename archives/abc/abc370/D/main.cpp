#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/segtree>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using S = int;
S op(S a, S b) { return a + b; }
S e() { return 0; }
using segtree = atcoder::segtree<S, op, e>;

int find_one(segtree &seg, int i, int j) {
    int s = i;
    while (j - i > 1) {
        int k = (i + j) / 2;
        if (seg.prod(s, k) == 0) {
            i = k;
        } else {
            j = k;
        }
    }
    return i;
}

int find_one_rev(segtree &seg, int i, int j) {
    int s = j;
    while (j - i > 1) {
        int k = (i + j) / 2;
        if (seg.prod(k, s) == 0) {
            j = k;
        } else {
            i = k;
        }
    }
    return i;
}

int main() {
    cout << fixed << setprecision(18);
    int H, W, Q;
    cin >> H >> W >> Q;
    vi R(Q), C(Q);
    rep(i, Q) {
        cin >> R[i] >> C[i];
        R[i]--;
        C[i]--;
    }
    vector<segtree> rows(H, segtree(W)), cols(W, segtree(H));
    rep(h, H) {
        rep(w, W) {
            rows[h].set(w, 1);
            cols[w].set(h, 1);
        }
    }
    rep(i, Q) {
        int r = R[i], c = C[i];
        if (rows[r].get(c) == 1) {
            rows[r].set(c, 0);
            cols[c].set(r, 0);
        } else {
            vpii break_points;
            int c1 = find_one(rows[r], c, W);
            break_points.emplace_back(r, c1);
            int r1 = find_one(cols[c], r, H);
            break_points.emplace_back(r1, c);
            int c2 = find_one_rev(rows[r], 0, c);
            break_points.emplace_back(r, c2);
            int r2 = find_one_rev(cols[c], 0, r);
            break_points.emplace_back(r2, c);
            for (auto [r, c] : break_points) {
                if (0 <= r && r < H && 0 <= c && c < W) {
                    rows[r].set(c, 0);
                    cols[c].set(r, 0);
                }
            }
        }
    }
    int ans = 0;
    rep(i, H) { ans += rows[i].all_prod(); }
    cout << ans << endl;
}
