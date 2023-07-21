#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll a, b;

int main()
{
    cin >> a >> b;
    if (a == b)
    {
        cout << 0 << endl;
        return 0;
    }
    if (a < b)
        swap(a, b);
    ll ans = 0;
    ll ab[2] = {a, b};

    while (ab[0] != ab[1])
    {
        ll n = ab[0] / ab[1];
        if (ab[0] % ab[1] != 0)
        {
            ab[0] -= ab[1] * n;
            ans += n;
            // cout << ab[0] << " " << ab[1] << endl;
            swap(ab[0], ab[1]);
        }
        else
        {
            ans += n - 1;
            break;
        }
    }
    cout << ans << endl;
}
