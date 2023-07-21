#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

bool visited[200010];
Graph<int> tree;
map<int, ll> m;
ll ans[200010];

void solve(int node)
{
    visited[node] = true;
    for (auto nv : tree[node])
    {
        if (visited[nv])
            continue;
        ans[nv] += ans[node] + m[nv];
        solve(nv);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    Graph<int> g;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    rep(i, n) visited[i] = false;
    queue<int> que;
    que.push(0);
    visited[0] = true;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : g[v])
        {
            if (visited[nv])
                continue;
            visited[nv] = true;
            tree[v].insert(nv);
            que.push(nv);
        }
    }

    rep(i, q)
    {
        int p, x;
        cin >> p >> x;
        p--;
        m[p] += x;
    }

    rep(i, n)
    {
        ans[i] = 0;
        visited[i] = false;
    }

    ans[0] = m[0];
    solve(0);

    rep(i, n) cout << ans[i] << " \n"[i == n - 1];
    // cout << endl;
}
