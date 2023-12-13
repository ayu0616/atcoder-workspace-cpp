#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N, M, K;
ll ans = 1e18;
vector<Edge> edges;
UnionFind uf(8LL);

void dfs(ll idx, vector<ll> use, UnionFind<ll> uf)
{
    if (use.size() == N - 1)
    {
        ll cost = 0;
        for (auto &i : use)
        {
            auto &e = edges[i];
            cost += e.cost;
            cost %= K;
        }
        chmin(ans, cost);
        return;
    }
    if (idx == edges.size())
        return;
    dfs(idx + 1, use, uf);
    use.push_back(idx);
    if(uf.same(*edges[idx].from, *edges[idx].to))
        return;
    uf.unite(*edges[idx].from, *edges[idx].to);
    dfs(idx + 1, use, uf);
}

int main()
{
    cin >> N >> M >> K;
    Graph g(N);
    rep(i, M)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g.add_edge(u, v, w);
        g.add_edge(v, u, w);
        edges.push_back({u, v, w});
    }
    vector<ll> use;
    dfs(0, use, uf);
    cout << ans << endl;
}
