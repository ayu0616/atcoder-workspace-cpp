#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n, q, l, r, x;
    cin >> n;
    vector<vector<ll>> idx(n + 1);
    rep(i, n)
    {
        ll a;
        cin >> a;
        idx[a].push_back(i);
    }
    cin >> q;

    while (q--)
    {
        cin >> l >> r >> x;
        cout << lower_bound(idx[x].begin(), idx[x].end(), r) - lower_bound(idx[x].begin(), idx[x].end(), l - 1) << endl;
    }
}
