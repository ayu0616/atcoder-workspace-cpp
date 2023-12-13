#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vvi G;
vi deg;
vector<bool> visited;
vpii ans;
int cnt = 0;

void dfs(int v)
{
    if (visited[v])
        return;
    visited[v] = true;
    if (v != 0 && deg[v] == 1)
    {
        cnt++;
        ans[v] = {cnt, cnt};
        return;
    }
    for (auto u : G[v])
    {
        if (visited[u])
            continue;
        dfs(u);
        ans[v].first = min(ans[v].first, ans[u].first);
        ans[v].second = max(ans[v].second, ans[u].second);
    }
}

int main()
{
    int N;
    cin >> N;
    G.resize(N);
    deg.resize(N);
    rep(i, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    visited = vector<bool>(N, false);
    ans = vpii(N, {1e9, 0});
    dfs(0);
    rep(i, N)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
