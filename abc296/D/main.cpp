#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

#define INF (ll)1e18

int main()
{
    ll n, m, x, ans = INF;
    cin >> n >> m;

    for (ll i = 1; i <= n; i++)
    {
        x = (m + i - 1) / i;
        if (x <= n)
            ans = min(ans, x * i);
        if (i > x)
            break;
    }
    if(ans == INF)
        ans = -1;
    cout << ans << endl;
}
