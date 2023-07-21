#include "../../lib.hpp"

// const ll MOD = 998244353;
// const ll MOD = 1000000007;
// const ll MOD = 1000000009;

// using mll = static_modll<MOD>;

ll bin_search(ll n, ll l, ll r, vl &v)
{
    if (r - l <= 1)
    {
        return l;
    }
    ll m = (l + r) / 2;
    if (v[m] <= n)
    {
        return bin_search(n, m, r, v);
    }
    else
    {
        return bin_search(n, l, m, v);
    }
}


int main()
{
    ll n, q;
    cin >> n;
    vl a(n), b(n);
    rep(i, n) cin >> a[i];
    b[0] = a[0];
    rep(i, n-1)
    {
        if (i % 2 == 1)
            b[i + 1] = b[i] + a[i + 1] - a[i];
        else
            b[i + 1] = b[i];
    }
    cin >> q;
    rep(i, q)
    {
        ll l, r;
        cin >> l >> r;
        ll ali = bin_search(l, 0, n, a);
        ll ari = bin_search(r, 0, n, a);
        ll ans = b[ari] - b[ali];
        if (ali % 2 == 1)
        {
            ans -= l - a[ali];
        }
        if (ari % 2 == 1)
        {
            ans -= a[ari] - r;
        }
        cout << ans << endl;
    }
}
