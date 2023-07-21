#if !__INCLUDE_LEVEL__
#include __FILE__

int main()
{
    int n, d;
    vector<vector<int>> x;
    cin >> n >> d;
    rep(_, n)
    {
        vector<int> v(d);
        rep(i, d)
        {
            cin >> v[i];
        }
        x.push_back(v);
    }

    int res = 0;
    rep(i, n - 1)
    {
        for (int j = i + 1; j < n; j++)
        {
            int dist = 0;
            rep(k, d) dist += pow(x[i][k] - x[j][k], 2);
            if (is_natural(dist))
                res++;
        }
    }
    cout << res << endl;
}

#else

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool is_natural(int x)
{
    bool res = false;
    rep(i, 200)
    {
        if (x == pow(i+1, 2))
        {
            res = true;
            break;
        }
    }
    return res;
}

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
