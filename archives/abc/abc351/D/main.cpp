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

int main() {
    cout << fixed << setprecision(18);
    cin >> H >> W;
    vs S(H);
    cin >> S;
    Graph G(H * W);
    UnionFind<ll> uf(H * W);
    vvb ok_pos(H, vb(W, false));
    rep(i, H) rep(j, W) {
        if (S[i][j] == '#') continue;
        bool ok = true;
        rep(k, 4) {
            ll ny = i + dy4[k];
            ll nx = j + dx4[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#') ok = false;
        }
        if (!ok) continue;
        ok_pos[i][j] = true;
        rep(k, 4) {
            ll ny = i + dy4[k];
            ll nx = j + dx4[k];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (S[ny][nx] == '#') continue;
            G.add_edge(to_idx(i, j), to_idx(ny, nx));
            bool ok = true;
            rep(l, 4) {
                ll ny = i + dy4[l];
                ll nx = j + dx4[l];
                if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
                if (S[ny][nx] == '#') ok = false;
            }
            if (ok) uf.unite(to_idx(i, j), to_idx(ny, nx));
        }
    }
    ll ans = 0;
    rep(i, H) rep(j, W) {
        if (S[i][j] == '#') continue;
        chmax(ans, 1LL);
        if (ok_pos[i][j]) {
            ll idx = to_idx(i, j);
            if (uf.is_root(idx)) {
                deque<ll> que;
                que.push_back(idx);
                vb visited(H * W, false);
                visited[idx] = true;
                ll score = 1;
                while (que.size()) {
                    ll cur = que.front();
                    que.pop_front();
                    for (auto e : G[cur]) {
                        if (visited[*e.to]) continue;
                        visited[*e.to] = true;
                        que.push_back(*e.to);
                        score++;
                    }
                }
                chmax(ans, score);
            }
        }
    }
    // rep(i, H) rep(j, W) {
    //     if (S[i][j] == '.') ans = 1;
    // }
    // vvb visited(H, vb(W, false));
    // vvb visited_local(H, vb(W, false));
    // function<ll(ll, ll)> dfs = [&](ll y, ll x) {
    //     if (y < 0 || y >= H || x < 0 || x >= W) return 0LL;
    //     if (visited_local[y][x]) return 0LL;
    //     visited[y][x] = true;
    //     visited_local[y][x] = true;
    //     if (S[y][x] == '#') return 0LL;
    //     bool ok = true;
    //     rep(i, 4) {
    //         ll ny = y + dy4[i];
    //         ll nx = x + dx4[i];
    //         if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
    //         if (S[ny][nx] == '#') ok = false;
    //     }
    //     ll score = 1;
    //     if (!ok) {
    //         return score;
    //     }
    //     score += dfs(y + 1, x);
    //     score += dfs(y, x + 1);
    //     score += dfs(y - 1, x);
    //     score += dfs(y, x - 1);
    //     ans = max(ans, score);
    //     return score;
    // };
    // rep(i, H) rep(j, W) {
    //     bool ok = true;
    //     rep(i, 4) {
    //         ll ny = i + dy4[i];
    //         ll nx = j + dx4[i];
    //         if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
    //         if (S[ny][nx] == '#') ok = false;
    //     }
    //     if (visited[i][j]) ok = false;
    //     if (ok) {
    //         visited_local.assign(H, vb(W, false));
    //         dfs(i, j);
    //     }
    // }
    cout << ans << endl;
}
