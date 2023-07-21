#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, q;
    cin >> n >> q;

    Graph<int> g;
    set<int> iso;
    rep(i, n) iso.insert(i);

    rep(i, q)
    {
        int kind;
        cin >> kind;
        if (kind == 1)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            g[u].insert(v);
            g[v].insert(u);
            iso.erase(u);
            iso.erase(v);
            cout<<iso.size()<<endl;
        }
        else
        {
            int v;
            cin >> v;
            v--;
            iso.insert(v);
            for(auto u:g[v]){
                g[u].erase(v);
                if(g[u].size()==0){
                    iso.insert(u);
                }
            }
            g[v].clear();
            cout<<iso.size()<<endl;
        }
    }
}
