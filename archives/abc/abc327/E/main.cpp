#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

// map<ll, long double> memo;
// long double touhi_sum(ll k)
// {
//     if (memo.count(k))
//         return memo[k];
//     long double res = 0;
//     k--;
//     while (k >= 0)
//     {
//         res += powl(0.9, k);
//         k--;
//     }
//     return memo[k] = res;
// }

ll N;

long double calc_rating(vl &perf, vi use)
{
    ll k = count(all(use), 1);
    if (k == 0)
        return 0;
    long double res = 0;
    int j = k - 1;
    rep(i, perf.size())
    {
        if (use[i] == 1)
        {
            res += powl(0.9, j) * perf[i];
            j--;
        }
    }
    res /= (1 - powl(0.9, k)) * 10;
    res -= (1200.0 / sqrtl(k));
    // debug(touhi_sum(k));
    return res;
}

struct State
{
    long double rating;
    vi use;
    State(long double r, vi u) : rating(r), use(u) {}
    State() : rating(-1e18), use(vi(N, 0)) {}
    bool operator<(const State &rhs) const
    {
        return rating < rhs.rating;
    }
};

int main()
{
    cin >> N;
    vector<long double> P(N);
    cin >> P;
    vector<vector<long double>> dp(N + 1, vector<long double>(N + 1, -1e18));
    dp[0][0] = 0;
    rep(i, N)
    {
        rep(j, i + 1)
        {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], 0.9 * dp[i][j] + P[i]);
        }
    }
    long double ans = -1200;
    rep(i, N) chmax(ans, dp[N][i + 1] / ((1.0 - powl(0.9, (i + 1))) * 10.0) - (1200.0 / sqrtl((i + 1))));
    cout << fixed << setprecision(10) << ans << endl;
}

// long double calc_rating(vl &perf)
// {
//     ll k = perf.size();
//     if (k == 0)
//         return 0;
//     long double res = 0;
//     int j = k - 1;
//     rep(i, k)
//     {
//         res += powl(0.9, j) * perf[i];
//         j--;
//     }
//     res /= touhi_sum(k);
//     res -= (1200.0 / sqrtl(k));
//     // debug(touhi_sum(k));
//     return res;
// }

// int main()
// {
//     ll N;
//     cin >> N;
//     vl P(N);
//     cin >> P;
//     vector<vector<pair<long double, vl>>> dp(N + 1, vector<pair<long double, vl>>(2, {0, {}}));
//     dp[0][0] = {0, {}};
//     rep(i, N)
//     {
//         vl p1 = dp[i][0].second, p2 = dp[i][1].second;
//         long double r1 = calc_rating(p1), r2 = calc_rating(p2);
//         if (r1 > r2)
//         {
//             dp[i + 1][0] = {r1, p1};
//         }
//         else
//         {
//             dp[i + 1][0] = {r2, p2};
//         }
//         p1.push_back(P[i]),
//         p2.push_back(P[i]);
//         r1 = calc_rating(p1), r2 = calc_rating(p2);
//         if (r1 > r2)
//         {
//             dp[i + 1][1] = {r1, p1};
//         }
//         else
//         {
//             dp[i + 1][1] = {r2, p2};
//         }
//     }
//     if (dp[N][0].second.size() == 0 && dp[N][0].first >= dp[N][1].first)
//     {
//         vl p = {*max_element(all(P))};
//         cout << calc_rating(p) << endl;
//     }
//     else if (dp[N][1].second.size() == 0 && dp[N][1].first >= dp[N][0].first)
//     {
//         vl p = {*max_element(all(P))};
//         cout << calc_rating(p) << endl;
//     }
//     else
//     {
//         cout << max(dp[N][0].first, dp[N][1].first) << endl;
//     }
// }
