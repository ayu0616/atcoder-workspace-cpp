#include <iostream>
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
    ll H, W;
    cin >> H >> W;
    vs C(H);
    cin >> C;
    pii start;
    rep(h, H) rep(w, W) if (C[h][w] == 'S') start = {h, w};
    set<pii> goals;
    rep(k, 4) {
        int gh = start.first + dy4[k];
        int gw = start.second + dx4[k];
        if (gh < 0 || gh >= H || gw < 0 || gw >= W) continue;
        if (C[gh][gw] == '#') continue;
        goals.insert({gh, gw});
    }
    if (goals.size() <= 1) {
        cout << "No" << endl;
        return 0;
    }
    for (auto s : goals) {
        for (auto g : goals) {
            if (s == g) continue;
            vvb visited(H, vb(W, false));
            visited[start.first][start.second] = true;
            deque<pii> q;
            q.push_back(s);
            while (!q.empty()) {
                auto p = q.front();
                q.pop_front();
                if (p == g) {
                    cout << "Yes" << endl;
                    return 0;
                }
                auto [h, w] = p;
                if (visited[h][w]) continue;
                visited[h][w] = true;
                rep(k, 4) {
                    int nh = h + dy4[k];
                    int nw = w + dx4[k];
                    if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
                    if (C[nh][nw] == '#') continue;
                    q.push_back({nh, nw});
                }
            }
        }
    }
    cout << "No" << endl;
}
