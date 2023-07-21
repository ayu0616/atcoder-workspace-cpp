#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n;
    cin >> n;
    map<string, ll> s;
    rep(i, n)
    {
        string t;
        cin >> t;
        sort(t.begin(), t.end());
        s[t]++;
    }
    ll ans = 0;
    for (auto p : s)
    {
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
}
