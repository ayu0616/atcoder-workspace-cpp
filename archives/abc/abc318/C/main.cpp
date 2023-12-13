#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll n, d, p;
    cin >> n >> d >> p;
    vl f(n);
    rep(i, n) cin >> f[i];
    sort(all(f));
    reverse(all(f));
    ll ans = 0;
    for (int i = 0; i < n; i += d)
    {
        ll pd = 0;
        rep(j, d)
        {
            if (i + j >= n)
                break;
            pd += f[i + j];
        }
        ans += min(pd, p);
    }
    cout << ans << endl;
}
