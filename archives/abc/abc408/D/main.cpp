#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

void solve(ll N, string S) {
    vector<pll> p;
    ll l = -1;
    rep(i, N) {
        if (S[i] == '1') {
            if (l == -1) {
                l = i;
            }
        } else {
            if (l != -1) {
                p.push_back({l, i});
                l = -1;
            }
        }
    }
    if (l != -1) {
        p.push_back({l, N});
    }
    int M = p.size();
    if (M == 0 || M == 1) {
        cout << 0 << endl;
        return;
    }
    vector<vector<ll>> dp(2, vector<ll>(2, INT_INF));
    dp[0][0] = 0;
    rep(i, M) {
        auto next_dp = dp;
        next_dp[0][0] = dp[0][0] + (p[i].second - p[i].first);
        if (i == 0) {
            next_dp[1][1] = 0;
        } else {
            next_dp[1][1] = min(dp[1][1] + (p[i].first - p[i - 1].second), dp[0][0]);
        }
        next_dp[1][0] = min(dp[1][1], dp[1][0]) + (p[i].second - p[i].first);
        dp = next_dp;
    }
    cout << min({dp[0][0], dp[0][1], dp[1][0], dp[1][1]}) << endl;
}

int main() {
    cout << fixed << setprecision(18);
    ll T;
    cin >> T;
    while (T--) {
        ll N;
        string S;
        cin >> N >> S;
        solve(N, S);
    }
}
