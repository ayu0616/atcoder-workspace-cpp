#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m, k, Q, p, q;
    cin >> n >> m;
    Graph g(n);
    UnionFind uf(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
        uf.unite(u, v);
    }
    cin >> k;
    vi x(k), y(k);
    set<pair<int, int>> root_pair;
    rep(i, k)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        root_pair.insert({uf.root(x[i]), uf.root(y[i])});
        root_pair.insert({uf.root(y[i]), uf.root(x[i])});
    }
    cin >> Q;

    rep(i, Q)
    {
        cin >> p >> q;
        p--;
        q--;
        if (root_pair.find({uf.root(p), uf.root(q)}) != root_pair.end())
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}
