#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n, x;
    cin >> n >> x;
    set<ll> a, b;
    rep(i, n)
    {
        ll t;
        cin >> t;
        a.insert(t);
        b.insert(t + x);
    }
    string ans = "No";
    for (auto i : a)
    {
        if (b.find(i) != b.end())
        {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
}
