#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, c;
    string s;
    ll w;
    vector<pair<ll, char>> p;
    cin >> n >> s;

    int ans = 0;
    rep(i, n)
    {
        cin >> w;
        p.push_back({w, s[i]});
        if (s[i] == '1')
            ans++;
    }

    sort(p.begin(), p.end());

    c = ans;
    rep(i, n)
    {
        if (p[i].second == '1')
            c--;
        else
            c++;
        if (i < (n - 1) && p[i].first == p[i + 1].first)
            continue;
        ans = max(ans, c);
    }
    cout << ans << endl;
}
