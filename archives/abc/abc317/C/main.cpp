#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll ans = 0;

void solve(int v, set<int> s, vvi &g, map<pii, ll> &w, ll d)
{
    if (s.size() == 0)
    {
        chmax(ans, d);
        return;
    }
    for (auto u : g[v])
    {
        if (s.find(u) != s.end())
        {
            s.erase(u);
            solve(u, s, g, w, d + w[{v, u}]);
            s.insert(u);
        }
    }
    chmax(ans, d);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vvi g(n);
    map<pii, ll> w;
    rep(i, m)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        w[{a, b}] = c;
        w[{b, a}] = c;
    }
    rep(i, n)
    {
        set<int> s;
        rep(j, n)
        {
            if (i != j)
            {
                s.insert(j);
            }
        }
        solve(i, s, g, w, 0);
    }
    cout << ans << endl;
}
