#include <stack>
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
    rep(M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
    }
    vi dist(N, -1);
    dist[0] = 0;
    int ans = INT_INF;
    queue<int> q;
    q.push(0);
    map<pii, int> edge_used;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : g[v]) {
            if (u == 0) {
                chmin(ans, dist[v] + 1);
                break;
            }
            if (dist[u] != -1) continue;
            dist[u] = dist[v] + 1;
            q.push(u);
        }
    }

    if (ans == INT_INF) {
        ans = -1;
    }
    cout << ans << endl;
}
