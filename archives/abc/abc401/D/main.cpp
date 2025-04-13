#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "../../lib.hpp"
#include "hassaku/all.hpp"

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;

const ll INF_COUNT = 200000 + 5;

pll combine_ranges(pll r1, pll r2) {
    ll min_val = INF_COUNT;
    ll max_val = -1;

    if (r1.first <= r1.second) {
        min_val = min(min_val, r1.first);
        max_val = max(max_val, r1.second);
    }

    if (r2.first <= r2.second) {
        min_val = min(min_val, r2.first);
        max_val = max(max_val, r2.second);
    }

    if (min_val > max_val) return {INF_COUNT, -1};
    return {min_val, max_val};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << fixed << setprecision(18);

    ll N, K;
    string S;
    cin >> N >> K >> S;

    vector<vector<pll>> dp_pref(N + 1, vector<pll>(2, {INF_COUNT, -1}));

    vector<vector<pll>> dp_suff(N + 1, vector<pll>(2, {INF_COUNT, -1}));

    dp_pref[0][0] = {0, 0};
    for (int i = 0; i < N; ++i) {
        pll next_dp0 = {INF_COUNT, -1};
        pll next_dp1 = {INF_COUNT, -1};
        pll p0 = dp_pref[i][0];
        pll p1 = dp_pref[i][1];

        if (S[i] == '.' || S[i] == '?') {
            pll combined = combine_ranges(p0, p1);
            if (combined.first <= combined.second) {
                next_dp0 = combined;
            }
        }

        if (S[i] == 'o' || S[i] == '?') {
            if (p0.first <= p0.second) {
                next_dp1 = {p0.first + 1, p0.second + 1};
            }
        }
        dp_pref[i + 1][0] = next_dp0;
        dp_pref[i + 1][1] = next_dp1;
    }

    dp_suff[N][0] = {0, 0};

    for (int i = N - 1; i >= 0; --i) {
        pll next_dp0 = {INF_COUNT, -1};
        pll next_dp1 = {INF_COUNT, -1};
        pll s0 = dp_suff[i + 1][0];
        pll s1 = dp_suff[i + 1][1];

        if (S[i] == '.' || S[i] == '?') {
            pll combined = combine_ranges(s0, s1);
            if (combined.first <= combined.second) {
                next_dp0 = combined;
            }
        }

        if (S[i] == 'o' || S[i] == '?') {
            if (s0.first <= s0.second) {
                next_dp1 = {s0.first + 1, s0.second + 1};
            }
        }
        dp_suff[i][0] = next_dp0;
        dp_suff[i][1] = next_dp1;
    }

    string T = S;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '?') {
            bool possible_o = false;
            bool possible_dot = false;

            pll p0_pref = dp_pref[i][0];
            pll s0_suff = dp_suff[i + 1][0];
            pll s1_suff = dp_suff[i + 1][1];

            if (p0_pref.first <= p0_pref.second) {
                pll suffix_range_for_o = s0_suff;
                if (suffix_range_for_o.first <= suffix_range_for_o.second) {
                    ll min_total = p0_pref.first + 1 + suffix_range_for_o.first;
                    ll max_total = p0_pref.second + 1 + suffix_range_for_o.second;

                    if (min_total <= K && K <= max_total) {
                        possible_o = true;
                    }
                }
            }

            pll p0_pref_dot = dp_pref[i][0];
            pll p1_pref_dot = dp_pref[i][1];
            pll s0_suff_dot = dp_suff[i + 1][0];
            pll s1_suff_dot = dp_suff[i + 1][1];

            pll prefix_range_for_dot = combine_ranges(p0_pref_dot, p1_pref_dot);

            pll suffix_range_for_dot = combine_ranges(s0_suff_dot, s1_suff_dot);

            if (prefix_range_for_dot.first <= prefix_range_for_dot.second && suffix_range_for_dot.first <= suffix_range_for_dot.second) {
                ll min_total = prefix_range_for_dot.first + 0 + suffix_range_for_dot.first;
                ll max_total = prefix_range_for_dot.second + 0 + suffix_range_for_dot.second;

                if (min_total <= K && K <= max_total) {
                    possible_dot = true;
                }
            }

            if (possible_o && possible_dot) {
                T[i] = '?';
            } else if (possible_o) {
                T[i] = 'o';
            } else {
                T[i] = '.';
            }
        }
    }

    cout << T << endl;

    return 0;
}
