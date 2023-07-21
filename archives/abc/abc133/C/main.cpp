#if !__INCLUDE_LEVEL__
#include __FILE__

ll n, m;

int main()
{
    // cin >> n;
    cin >> n >> m;
    int mod = 2019;
    ll ans = mod;
    for (ll i = n; i < m; i++)
    {
        for (ll j = i + 1; j <= m; j++)
        {
            ans = min(ans, (i * j) % mod);
            if (ans == 0)
                break;
        }
        if (ans == 0)
            break;
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
