#include "../../lib.hpp"

int n, m;
vector<int> primes;

int main()
{
    cin >> n;
    ll ans = 0;
    rep(i, n)
    {
        rep(j, n / (i + 1))
        {
            ans += (i + 1) * (j + 1);
        }
    }
    cout << ans << endl;
}
