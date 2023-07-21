#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    UnionFind<ll> uf(200010);
    rep(i, n)
    {
        ll al = a[i];
        ll ar = a[n - 1 - i];
        if (al != ar)
        {
            uf.unite(al, ar);
        }
    }

    ll ans = 0;
    set<ll> s;
    rep(i, n)s.insert(a[i]);
    for (auto i : s)
    {
        if (uf.root(i) == i)
        {
            ans += uf.size(i) - 1;
        }
    }

    cout << ans << endl;
}
