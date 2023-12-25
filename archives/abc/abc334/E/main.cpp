#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

constexpr char RED = '.', GREEN = '#';

int main() {
    int H, W;
    cin >> H >> W;
    vs S(H);
    cin >> S;

    int init_cnt = 0;
    vvb visited(H, vb(W, false));
    map<pii, int> mp;
    rep(h, H) rep(w, W) {
        if (visited[h][w]) continue;
        if (S[h][w] == RED) continue;
        init_cnt++;
        queue<pii> q;
        q.push({h, w});
        while (!q.empty()) {
            auto [ch, cw] = q.front();
            visited[ch][cw] = true;
            mp[{ch, cw}] = init_cnt;
            q.pop();
            for (auto [dh, dw] : {pii{1, 0}, pii{-1, 0}, pii{0, 1}, pii{0, -1}}) {
                int nh = ch + dh;
                int nw = cw + dw;
                if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
                if (visited[nh][nw]) continue;
                if (S[nh][nw] == RED) continue;
                visited[nh][nw] = true;
                q.push({nh, nw});
            }
        }
    }

    mint ans = 0;
    int cnt = 0;

    rep(h, H) rep(w, W) {
        if (S[h][w] == GREEN) continue;
        cnt++;
        set<int> s;
        for (auto [dh, dw] : {pii{1, 0}, pii{-1, 0}, pii{0, 1}, pii{0, -1}}) {
            int nh = h + dh;
            int nw = w + dw;
            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (S[nh][nw] == RED) continue;
            s.insert(mp[{nh, nw}]);
        }
        ans += init_cnt - s.size() + 1;
    }

    cout<<ans/cnt<<endl;
}
