#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll l1, l2, u1, u2, a, b;
char col(ll i, ll j)
{
    if (i - j == a - b && l1 + a <= i && i <= u1 + a && l1 + b <= j && j <= u1 + b)
        return '#';
    if (i + j == a + b && l2 + a <= i && i <= u2 + a && l2 + j <= b && b <= u2 + b)
        return '#';
    return '.';
}

int main()
{
    ll n, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    ll o_a = 1 - a, o_b = 1 - b;
    ll n_a = n - a, n_b = n - b;
    l1 = max(o_a, o_b), u1 = min(n_a, n_b);
    l2 = max(o_a, -n_b), u2 = min(n_a, -o_b);
    for (ll i = p; i <= q; i++)
    {
        for (ll j = r; j <= s; j++)
        {
            cout << col(i, j);
        }
        cout << endl;
    }
}
