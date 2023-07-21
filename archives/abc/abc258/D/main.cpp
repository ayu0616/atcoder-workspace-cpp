#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n, x, stage;
ll ans;
ll a[200000 + 10], b[200000 + 10], sa[200000 + 10], sb[200000 + 10];

int main()
{
    cin >> n >> x;
    int stage = 0;
    a[0] = 0;
    b[0] = 0;
    sa[0] = 0;
    sb[0] = 0;
    rep(i, n)
    {
        cin >> a[i + 1] >> b[i + 1];
        sa[i + 1] = sa[i] + a[i + 1];
        sb[i + 1] = sb[i] + b[i + 1];
    }
    ans = 1e18+10;
    for (ll i = 1; i <= min(n, x); i++)
    {
        ans = min(ans, sa[i] + sb[i] + (x - i) * b[i]);
    }
    cout << ans << endl;
}
