#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(3));
    rep(i, n - 1) rep(j, 3) cin >> a[i][j];
    ll zero = 0;
    rep(i, n)
    {
        ll x = 0;
        for (int j = i; j < n - 1; j++)
        {
            ll c = a[j][0];
            ll s = a[j][1];
            ll f = a[j][2];
            x = max(x, s);
            ll d = (-x) % f;
            if (d < 0)
                d += f;
            x += (c + d);
        }
        cout << x << endl;
    }
}
