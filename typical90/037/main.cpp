#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int W, N;
    cin >> W >> N;
    vi L(N), R(N), V(N);
    rep(i, N) cin >> L[i] >> R[i] >> V[i];
    vvl dp(N + 1, vl(W + 2, 1));
    dp[0][0] = 0;
    vector<SegTree> st(N + 1, SegTree(W + 1));
    rep(i, N + 1) st[i].update(0, W + 1, 1);
    rep(i, N + 1) st[i].update(0, 1, 0);
    rep(i, 1, N + 1) {
        dp[i] = dp[i - 1];
        rep(j, W + 1) {
            int cl = max(0, j - R[i-1]), cr = max(0, j - L[i-1] + 1);
            if (cl == cr) continue;
            ll val = st[i-1].query(cl, cr);
            if (val != 1) {
                chmin(dp[i][j], val - V[i-1]);
            }
        }
        rep(j, W + 1) st[i].update(j, j + 1, dp[i][j]);
    }
    ll ans = dp[N][W];
    cout << -ans << endl;
}
