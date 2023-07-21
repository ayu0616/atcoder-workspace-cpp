#if !__INCLUDE_LEVEL__
#include __FILE__

int n, m;
string s, t;

int main()
{
    // cin >> n;
    // cin >> n >> m;
    cin >> s >> t;
    int size = s.size();
    int ans = 0;
    rep(i, size)
    {
        if (s[i] != t[i])
            ans++;
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
