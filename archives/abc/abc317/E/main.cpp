#include <queue>

#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr char* way = ">v<^";

int main() {
    int H, W;
    cin >> H >> W;
    vs A(H);
    cin >> A;
    rep(h, H) rep(w, W) {
        rep(way_i, 4) {
            if (A[h][w] == way[way_i]) {
                int nh = h + dy4[way_i];
                int nw = w + dx4[way_i];
                while (0 <= nh && nh < H && 0 <= nw && nw < W && (A[nh][nw] == '.' || A[nh][nw] == '!')) {
                    A[nh][nw] = '!';
                    nh += dy4[way_i];
                    nw += dx4[way_i];
                }
            }
        }
    }

    pii start, goal;
    rep(h, H) rep(w, W) {
        if (A[h][w] == 'S') {
            start = {h, w};
            A[h][w] = '.';
        }
        if (A[h][w] == 'G') {
            goal = {h, w};
            A[h][w] = '.';
        }
    }

    vvi dist(H, vi(W, INT_INF));
    queue<pii> q;
    q.push(start);
    dist[start.first][start.second] = 0;
    while (!q.empty()) {
        auto [h, w] = q.front();
        q.pop();
        rep(way_i, 4) {
            int nh = h + dy4[way_i];
            int nw = w + dx4[way_i];
            if (0 <= nh && nh < H && 0 <= nw && nw < W && A[nh][nw] == '.' && dist[nh][nw] == INT_INF) {
                dist[nh][nw] = dist[h][w] + 1;
                q.push({nh, nw});
            }
        }
    }
    if (dist[goal.first][goal.second] == INT_INF) {
        cout << -1 << endl;
    } else {
        cout << dist[goal.first][goal.second] << endl;
    }
}
