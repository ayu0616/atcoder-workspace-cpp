#include "../../lib.hpp"

// #define MOD 1000000007
#define MOD 998244353

using mint = static_modint<MOD>;

ll n;
map<ll, mint> memo;

mint p(ll k)
{
    if (k >= n)
        return k == n ? 1 : 0;
    if (memo.count(k) > 0)
        return memo[k];
    mint res = 0;
    for (int i = 2; i <= 6; i++)
    {
        res += p(k * i);
    }
    return memo[k] = res / 5;
}

int main()
{
    cin >> n;
    cout << p(1) << endl;
}
