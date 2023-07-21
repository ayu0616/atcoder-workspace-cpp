#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> w(n);
    rep(i, n) cin >> w[i].first >> w[i].second;
    sort(w.begin(), w.end(), [](pair<ll, ll> a, pair<ll, ll> b)
         { return a.second < b.second; });
    string ans = "Yes";
    ll t = 0;
    rep(i, n)
    {
        t += w[i].first;
        if (t > w[i].second)
        {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
}
