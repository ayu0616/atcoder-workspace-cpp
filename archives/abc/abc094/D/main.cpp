#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll x = a.back();
    ll diff = 1e9;
    ll y = a[0];
    rep(i, n)
    {
        if (diff > abs(x - a[i] * 2))
        {
            diff = abs(x - a[i] * 2);
            y = a[i];
        }
    }
    cout << x << " " << y << endl;
}
