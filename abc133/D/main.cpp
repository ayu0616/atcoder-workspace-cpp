#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m;
vector<ll> a;

int main()
{
    cin >> n;
    rep(i, n)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }
    ll ans[n];
    ans[0] = 0;
    rep(i, n)
    {
        if (i % 2 == 0)
            ans[0] += a[(i + 0) % n];
        else
            ans[0] -= a[(i + 0) % n];
    }
    for (int i = 1; i < n; i++)
    {
        ans[i] = -ans[i - 1] + 2 * a[i - 1];
    }

    rep(i, n)
    {
        cout << ans[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
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
