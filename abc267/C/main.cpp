#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, m, a[200010], s[200010];

int main()
{
    cin >> n >> m;
    s[0] = 0;
    rep(i, n)
    {
        cin >> a[i];
        s[i + 1] = s[i] + a[i];
    }
    // rep(i, n) cout << s[i + 1] << endl;
    ll tmp = 0;
    rep(i, m) tmp += a[i] * (i + 1);
    // cout << tmp << endl;
    ll ans = tmp;
    for (ll i = 1; i <= n - m; i++)
    {
        // cout << tmp << endl;
        tmp += a[i + m - 1] * m - (s[i + m - 1] - s[i - 1]);
        // cout << tmp << endl;
        // cout << endl;
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
