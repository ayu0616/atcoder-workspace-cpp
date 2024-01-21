#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;

    int cnt = 0;
    map<pii, int> pos_memo;
    auto pos = [&](int r, int c) {
        pii p = {r, c};
        if (pos_memo[p]) return pos_memo[p] - 1;
        cnt++;
        return pos_memo[p] = cnt;
    };

    UnionFind uf(H * W);
    map<pii, bool> red;

    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int r, c;
            cin >> r >> c;
            r--, c--;
            int cur_pos = pos(r, c);
            red[{r, c}] = true;
            rep(i, 4) {
                int nr = r + dy4[i], nc = c + dx4[i];
                if (nr < 0 || H <= nr || nc < 0 || W <= nc) continue;
                int n_pos = pos(nr, nc);
                if (red[{nr, nc}]) uf.unite(cur_pos, n_pos);
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--, ca--, rb--, cb--;
            int pos_a = pos(ra, ca), pos_b = pos(rb, cb);
            yes_no(red[{ra, ca}] && red[{rb, cb}] && uf.same(pos_a, pos_b));
        }
    }
}
