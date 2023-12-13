#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

const int MAX = 1e6;
int ans = 1;
int N, M;
Graph g(2e5 + 10);
vector<bool> used(2e5 + 10, false);

void solve(int v)
{
    used[v] = true;
    for (auto e : g[v])
    {
        if (used[e.to->id])
            continue;
        solve(*e.to);
        if (++ans >= MAX)
            return;
    }
    used[v] = false;
}

int main()
{
    cin >> N >> M;

    rep(i, M)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }

    solve(0);
    cout << min(ans, MAX) << endl;
}
