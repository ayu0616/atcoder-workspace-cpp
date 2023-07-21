#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll x, y, z;
    string s;
    cin >> x >> y >> z >> s;

    vector<pair<char, int>> sv;
    sv.push_back({s[0], 1});
    rep2(i, 1, s.size())
    {
        if (s[i] == sv.back().first)
            sv.back().second++;
        else
            sv.push_back({s[i], 1});
    }

    vvl dp(sv.size() + 1, vl(2, 0));
    dp[0][1] = 1e9;
    rep(i, sv.size())
    {
        int k = sv[i].second;
        if (sv[i].first == 'A')
        {
            dp[i + 1][0] = min(dp[i][0] + k * y, dp[i][1] + k * y + z);
            dp[i + 1][1] = min(dp[i][0] + k * x + z, dp[i][1] + k * x);
        }
        else
        {
            dp[i + 1][0] = min(dp[i][0] + k * x, dp[i][1] + k * x + z);
            dp[i + 1][1] = min(dp[i][0] + k * y + z, dp[i][1] + k * y);
        }
    }

    cout << min(dp[sv.size()][0], dp[sv.size()][1]) << endl;

    // bool is_caps = false;

    // ll ans = 0;
    // for (auto p : sv)
    // {
    //     int k = p.second;
    //     if (is_caps)
    //     {
    //         if (p.first == 'A')
    //         {
    //             if (k * x >= k * y + z)
    //             {
    //                 ans += k * y + z;
    //                 is_caps = false;
    //             }
    //             else
    //             {
    //                 ans += k * x;
    //             }
    //         }
    //         else
    //         {
    //             if (k * y >= k * x + z)
    //             {
    //                 ans += k * x + z;
    //                 is_caps = false;
    //             }
    //             else
    //             {
    //                 ans += k * y;
    //             }
    //         }
    //     }
    //     else
    //     {
    //         if (p.first == 'A')
    //         {
    //             if (k * y >= k * x + z)
    //             {
    //                 ans += k * x + z;
    //                 is_caps = true;
    //             }
    //             else
    //             {
    //                 ans += k * y;
    //             }
    //         }
    //         else
    //         {
    //             if (k * x >= k * y + z)
    //             {
    //                 ans += k * y + z;
    //                 is_caps = true;
    //             }
    //             else
    //             {
    //                 ans += k * x;
    //             }
    //         }
    //     }
    // }

    // cout << ans << endl;
}
