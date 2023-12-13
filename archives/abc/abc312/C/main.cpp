#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vl a(n), b(m);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, m)
    {
        cin >> b[i];
    }
    map<ll, pll> mp;
    rep(i, n)
    {
        mp[a[i]].first++;
    }
    rep(i, m)
    {
        mp[b[i]].second++;
    }
    int a_cnt = 0, b_cnt = m;
    ll prev = -1;
    for (auto &&p : mp)
    {
        a_cnt += p.second.first;
        if (b_cnt == 0)
        {
            cout << prev + 1 << endl;
            return 0;
        }
        else if (a_cnt >= b_cnt)
        {
            cout << p.first << endl;
            return 0;
        }
        b_cnt -= p.second.second;
        prev = p.first;
    }
    // sort(all(a));
    // sort(all(b));
    // reverse(all(a));
    // reverse(all(b));
    // int cnt = 0;
    // ll ans = -1;
    // rep(i, n)
    // {
    //     if (i < m)
    //     {
    //         rep2(j, cnt, m)
    //         {
    //             if (a[i] < b[j])
    //             {
    //                 cnt++;
    //             }
    //             else
    //             {
    //                 break;
    //             }
    //         }
    //         if (m - cnt <= i)
    //         {
    //             ans = a[i];
    //         }
    //     }
    // }
    // cout << ans << endl;
}
