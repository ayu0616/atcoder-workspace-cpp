#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll pows[10000001];
ll k;

ll pow(ll a);

int main()
{
    rep(i, 10000001)
    {
        pows[i] = 0;
    }
    pows[0] = 0;
    cin >> k;
    ll x = 7;
    ll cnt = 1;
    if (k % 2 == 0)
    {
        cout << -1 << endl;
        return 0;
    }
    while (x % k != 0)
    {
        x += 7 * pow(cnt);
        x %= k;
        if (cnt > 1000000)
        {
            cout << -1 << endl;
            return 0;
        }
        cnt++;
    }
    cout << cnt << endl;
}

ll pow(ll a)
{
    if (pows[a] != 0)
    {
        return pows[a];
    }
    if (a == 0)
    {
        return 1;
    }
    ll tmp = pow(a - 1);
    pows[a] = tmp * 10;
    pows[a] %= k;
    return pows[a];
}