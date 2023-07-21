#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m;

int main()
{
    // cin >> n;
    cin >> n >> m;
    vector<ll> a;
    vector<ll> dp;
    dp.emplace_back(1e10);
    rep(i, n)
    {
        ll x;
        cin >> x;
        a.emplace_back(x);
        dp.emplace_back(1e10);
    }
    Graph g(m, true);
    rep(i, n)
    {
        for (auto v : g.edges[i + 1])
        {
            dp[v] = min(dp[i + 1], dp[v]);
            dp[v] = min(a[i], dp[v]);
        }
    }
    ll ans = -1e10;
    rep(i, n)
    {
        ans = max(ans, a[i] - dp[i + 1]);
    }
    cout << ans << endl;
}

#else

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

class Graph
{
public:
    unordered_map<int, set<int>> edges;

    Graph(int n, bool directed = false)
    {
        rep(_, n)
        {
            int u, v;
            cin >> u >> v;
            this->edges[u].insert(v);
            if (!directed)
            {
                this->edges[v].insert(u);
            }
        }
    }
};

#endif