#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    Graph<int> g;
    UnionFind uf(n);
    rep(i, n - 1)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
        uf.unite(u, v);
    }
    vi lv;
    int sum_lv = 0;
    rep(i, n)
    {
        if (g[i].size() > 2)
        {
            lv.push_back(g[i].size());
            sum_lv += g[i].size();
        }
    }
    int two_num = (n - lv.size() - sum_lv) / 3;

    rep(i, two_num) cout << 2 << (i == two_num - 1 ? "" : " ");
    if(lv.size()>0)
        cout << " ";
    sort(lv.begin(), lv.end());
    rep(i, lv.size()) cout << lv[i] << (i == lv.size() - 1 ? "" : " ");
    cout << endl;
}
