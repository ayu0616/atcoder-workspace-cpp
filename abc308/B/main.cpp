#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vi p(m + 1);
    vector<string> c(n), d(m);
    map<string, int> mp;
    rep(i, n) { cin >> c[i]; }
    rep(i, m) { cin >> d[i]; }
    rep(i, m+1) { cin >> p[i]; }
    rep(i, m)
    {
        mp[d[i]] = p[i + 1];
    }
    int ans = 0;
    rep(i, n)
    {
        if (find(all(d), c[i]) != d.end())
        {
            ans += mp[c[i]];
        }
        else
        {
            ans += p[0];
        }
    }
    cout << ans << endl;
}
