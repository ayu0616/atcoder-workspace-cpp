#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
ll ans = 0;
string N;
void solve(int s) {
    vector dp(N.size() + 1, vector(s + 1, vector(s, vector(2, 0LL))));
    dp[0][0][0][1] = 1;
    rep(d, N.size()) rep(i, s + 1) rep(j, s) rep(f, 2) rep(t, 10) {
        if (i + t > s) continue;
        if (f && (t > N[d] - '0')) continue;
        dp[d + 1][i + t][(j * 10 + t) % s][f && (t == N[d] - '0')] += dp[d][i][j][f];
    }
    rep(f, 2) ans += dp[N.size()][s][0][f];
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    rep(s, 1, 9 * 14 + 1) { solve(s); }
    cout << ans << endl;
}
