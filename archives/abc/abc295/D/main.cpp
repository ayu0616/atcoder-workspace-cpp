#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    string s;
    cin >> s;
    set<char> odds;
    map<set<char>, ll> m;
    m[odds]++;
    rep(i, s.size())
    {
        char c = s[i];
        if (odds.count(c))
            odds.erase(c);
        else
            odds.insert(c);
        m[odds]++;
    }
    ll ans = 0;
    for (auto [k, v] : m)
    {
        ans += (v * (v - 1) / 2);
    }
    cout << ans << endl;
}
