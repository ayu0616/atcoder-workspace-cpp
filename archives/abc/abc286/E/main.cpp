#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

#define MAX 10000

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    int q;
    cin >> q;

    Graph<int> g, rev;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'Y')
                g[i].insert(j);
            rev[j].insert(i);
        }

    vector<vector<pair<int, ll>>> dist(n, vector<pair<int, ll>>(n, {MAX, 0}));
    rep(i, n)
    {
        dist[i][i] = {0, 0};
        for (auto v : g[i])
        {
            dist[i][v] = {1, a[v]};
        }
    }
    rep(k, n)
    {
        rep(i, n)
        {
            rep(j, n)
            {
                // if (dist[i][k].first == MAX || dist[k][j].first == MAX)
                //     continue;
                if (dist[i][j].first > (dist[i][k].first + dist[k][j].first))
                {
                    dist[i][j].first = dist[i][k].first + dist[k][j].first;
                    dist[i][j].second = dist[i][k].second + dist[k][j].second;
                }
                else if (dist[i][j].first == (dist[i][k].first + dist[k][j].first))
                {
                    dist[i][j].second = max(dist[i][j].second, dist[i][k].second + dist[k][j].second);
                }
            }
        }
    }

    // rep(i, n) rep(j, n) cout << i << ", " << j << " " << dist[i][j].first << endl;

    rep(i, q)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (dist[u][v].first == MAX)
            cout << "Impossible" << endl;
        else
            cout << dist[u][v].first << " " << dist[u][v].second + a[u] << endl;
    }
}