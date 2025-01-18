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
    vl A(N);
    cin >> A;
    Graph g(N);
    vl cost(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
        cost[u] += A[v];
        cost[v] += A[u];
    }
    set<pair<ll, int>> s;
    rep(i, N) { s.insert({cost[i], i}); }
    ll ans = 0;
    while (!s.empty()) {
        auto [c, i] = *s.begin();
        s.erase(s.begin());
        chmax(ans, c);
        for (auto e : g[i]) {
            int j = *e.to;
            if (s.count({cost[j], j})) {
                s.erase({cost[j], j});
                cost[j] -= A[i];
                s.insert({cost[j], j});
            }
        }
    }
    cout << ans << endl;
}
