#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll x, a, d, n;
    cin >> x >> a >> d >> n;
    ll mi = min(a, a + d * (n - 1));
    ll ma = max(a, a + d * (n - 1));
    if (x <= mi)
    {
        cout << abs(mi - x) << endl;
    }
    else if (x >= ma)
    {
        cout << abs(x - ma) << endl;
    }
    else
    {
        ll m = (x - a) / d;
        ll ans = min(abs(x - (a + d * m)), abs(x - (a + d * (m + 1))));
        cout << ans << endl;
    }
}
