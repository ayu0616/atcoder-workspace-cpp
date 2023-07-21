#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n, p, q;
    cin >> n;
    ll upper = pow(n, 1.0 / 3.0);

    vector<ll> primes = create_primes(upper);
    ll prime_cnt = primes.size();
    ll ans = 0;

    rep(i, prime_cnt)
    {
        q = primes[i];
        for (ll j = 0; j < i; j++)
        {
            p = primes[j];
            if (p * pow(q, 3) <= n)
                ans++;
            else
                break;
        }
    }

    cout << ans << endl;
}
