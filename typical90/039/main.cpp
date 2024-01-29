#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vi A(N - 1), B(N - 1);
    Graph g(N);
    rep(i, N - 1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        A[i] = a, B[i] = b;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    vl dp(N, 1);
    vb visited(N, false);
    function<void(int)> dfs;
    dfs = [&](int v) {
        visited[v] = true;
        for (auto e : g[v]) {
            int u = e;
            if (!visited[u]) {
                dfs(u);
                dp[v] += dp[u];
            }
        }
    };
    dfs(0);

    ll ans = 0;
    rep(i, N - 1) {
        ll r = min(dp[A[i]], dp[B[i]]);
        ans += r * (N - r);
    }
    cout << ans << endl;
}
