#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n;
    cin >> n;
    ll m = 1;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            m = i;
        }
    }
    cout << (ll)log10(n / m) + 1 << endl;
}
