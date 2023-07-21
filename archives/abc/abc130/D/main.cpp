#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, k, a[100010], s[100010], ans = 0;

int main()
{
    cin >> n >> k;
    s[0] = 0;
    rep(i, n)
    {
        cin >> a[i];
        s[i + 1] = a[i] + s[i];
    }
    ll r = 0;
    for (ll l = 1; l <= n; l++)
    {
        r = max(r, l);
        while (r <= n && s[r] - s[l - 1] < k)
            r++;
        if (r <= n)
            ans += n - r + 1;
    }
    cout << ans << endl;
}
