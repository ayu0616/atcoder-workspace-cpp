#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int H, W, Y;
    cin >> H >> W >> Y;
    vvi A(H, vi(W));
    cin >> A;
    map<int, int> mp;
    vvb sunk(H, vb(W));
    int cur = 0;
    using cell = pair<int, pair<int, int>>;
    priority_queue<cell, vector<cell>, greater<cell>> pq;
    rep(h, H) {
        rep(w, W) {
            if (!(w == 0 || w == W - 1 || h == 0 || h == H - 1)) {
                continue;
            }
            pq.push({A[h][w], {h, w}});
        }
    }
    rep(t, 1, Y + 1) {
        cur++;
        int cnt = 0;
        while (!pq.empty() && pq.top().first <= cur) {
            auto [a, p] = pq.top();
            pq.pop();
            auto [h, w] = p;
            if (sunk[h][w]) {
                continue;
            }
            sunk[h][w] = true;
            cnt++;
            for (auto [dh, dw] : {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                int nh = h + dh, nw = w + dw;
                if (0 <= nh && nh < H && 0 <= nw && nw < W) {
                    pq.push({A[nh][nw], {nh, nw}});
                }
            }
        }
        mp[t] = cnt;
    }

    int ans = mp[0];
    rep(y, 1, Y + 1) {
        ans += mp[y];
        cout << (H * W) - ans << endl;
    }
}
