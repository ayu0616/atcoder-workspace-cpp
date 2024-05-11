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
    ll N, M;
    cin >> N >> M;
    Graph g(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
    }
    ll ans = 0;

    rep(u_s, N) {
        vb visited(N, false);
        visited[u_s] = true;
        queue<int> q;
        q.push(u_s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (visited[v]) continue;
                visited[v] = true;
                ans++;
                q.push(v);
            }
        }
    }

    cout << ans-M << endl;
}
