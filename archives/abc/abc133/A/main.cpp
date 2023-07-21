#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m, a, b;

int main()
{
    cin >> n >> a >> b;
    cout << min(a * n, b) << endl;
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
