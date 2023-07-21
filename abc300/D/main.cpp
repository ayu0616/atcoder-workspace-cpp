#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, ans = 0;
vector<ll> p;

int main()
{
    cin >> n;
    p = create_primes(powl(n / 12, 0.5));
    for (int ai = 0; ai < p.size(); ai++)
    {
        ll a = p[ai];
        if(powl(a, 5)>n)
            break;
        for (int bi = ai + 1; bi < p.size(); bi++)
        {
            ll  b = p[bi];
            if(powl(a, 2)*powl(b, 3)>n)
                break;
            for (int ci = bi + 1; ci < p.size(); ci++)
            {
                ll  c = p[ci];
                if (powl(a, 2) * b * powl(c, 2) > n)
                    break;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
