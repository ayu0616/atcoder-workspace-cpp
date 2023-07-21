#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll fac(int n) // 階乗を求める
{
    ll res = 1;
    rep(i, n)
    {
        res *= i + 1;
    }
    return res;
}

int main()
{
    int n, t, m;
    cin >> n >> t >> m;
    Graph g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b, false);
    }

    ll ans = 1;

    vector<set<int>> teams(n);
    rep(i, n) rep(j, t)
    {
        teams[i].insert(j);
    }

    rep(i, n)
    {
        rep(j, i)
        {
            bool ok = false;
            for (auto e : g[j])
            {
                if (e.to.id == i)
                {
                    ok = true;
                    break;
                }
            }
            if (ok)
                teams[i].erase(min_element(all(teams[i])));
        }
    }

    rep(i, n)
    {
        ans *= teams[i].size();
    }

    cout << ans / fac(t) << endl;
}
