#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n;
ll t, c[200010], r[200010];

int main()
{
    cin >> n >> t;
    rep(i, n) cin >> c[i];
    rep(i, n) cin >> r[i];
    vector<ll> idx, idx_no;
    rep(i, n) if (c[i] == t) idx.push_back(i);
    rep(i, n) if (c[i] == c[0]) idx_no.push_back(i);
    ll ans = 0, tmp = 0;
    if (idx.empty())
    {
        for (auto i : idx_no)
        {
            if (r[i] > tmp)
            {
                tmp = r[i];
                ans = i + 1;
            }
        }
    }
    else
    {
        for (auto i : idx)
        {
            if (r[i] > tmp)
            {
                tmp = r[i];
                ans = i + 1;
            }
        }
    }
    cout << ans << endl;
}
