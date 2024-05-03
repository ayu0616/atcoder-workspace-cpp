#include <numeric>

#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vpii holes;
    while (N--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        holes.emplace_back(a, b);
    }
    vvi grid(H, vi(W, 0));
    rep(h, H) rep(w, W) { grid[h][w] = min({H - h, W - w}); }
    vvi dist(H, vi(W, INT_INF));
    for (auto [a, b] : holes) {
        deque<pii> q;
        q.emplace_back(a, b);
        dist[a][b] = 0;
        grid[a][b] = 0;
        while (!q.empty()) {
            auto [h, w] = q.front();
            q.pop_front();
            for (auto [dh, dw] : vpii{{-1, 0}, {0, -1}, {-1, -1}}) {
                int nh = h + dh, nw = w + dw;
                if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
                bool updated = false;
                updated |= chmin(dist[nh][nw], dist[h][w] + 1);
                updated |= chmin(grid[nh][nw], dist[nh][nw]);
                if (updated) q.emplace_back(nh, nw);
            }
        }
    }
    // cout << grid << endl;
    ll ans = accumulate(all(grid), 0LL, [](ll acc, vi &v) { return acc + accumulate(all(v), 0LL); });
    cout << ans << endl;
}
