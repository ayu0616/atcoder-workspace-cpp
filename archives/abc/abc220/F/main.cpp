#include <functional>
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
    ll N;
    cin >> N;
    Graph G(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G.add_edge(u, v);
        G.add_edge(v, u);
    }
    vl cnt(N, 1);
    vl ans(N, 0);
    vb visited(N, false);
    function<void(int, int)> dfs = [&](int v, int d) {
        visited[v] = true;
        ans[0] += d;
        for (auto e : G[v]) {
            int u = *e.to;
            if (visited[u]) continue;
            dfs(u, d + 1);
            cnt[v] += cnt[u];
        }
    };
    dfs(0, 0);
    visited = vb(N, false);
    function<void(int)> dfs2 = [&](int v) {
        visited[v] = true;
        for (auto e : G[v]) {
            int u = *e.to;
            if (visited[u]) continue;
            ans[u] = ans[v] - 2 * cnt[u] + N;
            dfs2(u);
        }
    };
    dfs2(0);
    rep(i, N) cout << ans[i] << endl;
}
