#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);
    rep(i, M) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.add_edge(u, v, w);
    }
    vvl d = g.warshall_floyd();
    rep(i, N) rep(j, N) if (d[i][j] == -1) d[i][j] = LL_INF;
    vvl dp(1 << N, vl(N, LL_INF));
    rep(i, N) dp[1 << i][i] = 0;
    rep(i, 1 << N) {
        rep(j, N) {
            if (dp[i][j] == LL_INF) continue;
            rep(k, N) {
                if (i >> k & 1) continue;
                if (d[j][k] == LL_INF) continue;
                chmin(dp[i | 1 << k][k], dp[i][j] + d[j][k]);
            }
        }
    }
    ll ans = min(dp[(1 << N) - 1]);
    if (ans == LL_INF)
        cout << "No" << endl;
    else
        cout << ans << endl;
}
