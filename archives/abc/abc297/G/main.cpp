#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, l, r, a[200010];

int main()
{
    cin >> n >> l >> r;
    rep(i, n) cin >> a[i];
    ll tmp = 0;
    rep(i, n)
    {
        tmp += (a[i] - l) / r;
        if ((a[i] - l) % r != 0)
            tmp++;
    }
    // tmp += 1 - n % 2;
    if (tmp % 2 == 0)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "First" << endl;
    }
}
