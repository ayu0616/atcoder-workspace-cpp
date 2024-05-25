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
    ll N, M, K;
    cin >> N >> M >> K;
    Graph g1(N), g2(N);
    rep(i, M) {
        int u, v, a;
        cin >> u >> v >> a;
        u--;
        v--;
        if (a == 1) {
            g1.add_edge(u, v);
            g1.add_edge(v, u);
        } else {
            g2.add_edge(u, v);
            g2.add_edge(v, u);
        }
    }
    set<int> S;
    rep(i, K) {
        int s;
        cin >> s;
        S.insert(s - 1);
    }

    Graph g[2] = {g1, g2};
    vl dist1(N, LL_INF), dist2(N, LL_INF);
    vl dist[2] = {dist1, dist2};

    dist[0][0] = 0;
    deque<pii> q;
    q.emplace_front(0, 0);
    while (!q.empty()) {
        auto [v, a] = q.front();
        q.pop_front();
        for (auto &e : g[a][v]) {
            int u = *e.to;
            if (chmin(dist[a][u], dist[a][v] + 1)) {
                q.emplace_back(u, a);
            }
        }
        if (S.count(v)) {
            for (auto &e : g[a ^ 1][v]) {
                int u = *e.to;
                if (chmin(dist[a ^ 1][u], dist[a][v] + 1)) {
                    q.emplace_back(u, a ^ 1);
                }
            }
        }
    }
    ll ans = min(dist[0][N - 1], dist[1][N - 1]);
    if (ans == LL_INF) ans = -1;
    cout << ans << endl;
}
