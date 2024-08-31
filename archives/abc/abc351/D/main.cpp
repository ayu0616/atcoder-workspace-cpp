#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll H, W;
int to_idx(ll y, ll x) { return y * W + x; }
pii to_pos(int idx) { return {idx / W, idx % W}; }

int main() {
    cout << fixed << setprecision(18);
    cin >> H >> W;
    vs S(H);
    cin >> S;
    UnionFind<int> uf(H * W);
    vs S1 = S;
    rep(y, H) rep(x, W) {
        if (S[y][x] == '#') continue;
        rep(i, 4) {
            ll ny = y + dy4[i];
            ll nx = x + dx4[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#') {
                S1[y][x] = '#';
            }
        }
    }
    deque<pii> q;
    vb visited(H * W);
    rep(y, H) rep(x, W) {
        if (S1[y][x] == '#') continue;
        if (visited[to_idx(y, x)]) continue;
        q.push_back({y, x});
        while (!q.empty()) {
            auto [cy, cx] = q.front();
            q.pop_front();
            if (visited[to_idx(cy, cx)]) continue;
            visited[to_idx(cy, cx)] = true;
            rep(i, 4) {
                ll ny = cy + dy4[i];
                ll nx = cx + dx4[i];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (S1[ny][nx] == '#') continue;
                uf.unite(to_idx(cy, cx), to_idx(ny, nx));
                q.push_back({ny, nx});
            }
        }
    }
    vi groups;
    rep(y, H) rep(x, W) {
        if (S1[y][x] == '#') continue;
        if (uf.root(to_idx(y, x)) == to_idx(y, x)) {
            groups.push_back(to_idx(y, x));
        }
    }
    if (groups.empty()) {
        cout << 1 << endl;
        return 0;
    }
    vi group_scores;
    for (int group : groups) {
        group_scores.push_back(uf.size(group));
    }
    map<int, int> gp_map;
    rep(i, group_scores.size()) { gp_map[groups[i]] = i; }
    rep(y, H) rep(x, W) {
        if (S[y][x] == '.' && S1[y][x] == '#') {
            vb added(groups.size());
            rep(i, 4) {
                ll ny = y + dy4[i];
                ll nx = x + dx4[i];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (S1[ny][nx] == '.') {
                    int idx2 = to_idx(ny, nx);
                    int group = uf.root(idx2);
                    if (!added[gp_map[group]]) {
                        group_scores[gp_map[group]]++;
                        added[gp_map[group]] = true;
                    }
                }
            }
        }
    }
    int ans = *max_element(all(group_scores));
    cout << ans << endl;
}
