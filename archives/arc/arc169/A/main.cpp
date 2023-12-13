#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vl A(N), P(N - 1);
    cin >> A >> P;
    rep(i, N - 1) P[i]--;
    Graph g(N);
    rep(i, 1, N) { g.add_edge(P[i - 1], i); }
    vvi depth(N);
    int max_depth = 0;
    auto dfs = [&](auto &&f, int cur, int par, int d) -> void {
        max_depth = max(max_depth, d);
        depth[cur].push_back(d);
        for (auto &&e : g[cur]) {
            if (*e.to == par) continue;
            f(f, *e.to, cur, d + 1);
        }
    };
    dfs(dfs, 0, -1, 0);
    ll s = A[0];
    rep(i, 1, N) rep(j, depth[i].size()) { s += A[i] * (max_depth - depth[i][j] + 1); }
    ll ans = 0;
    rep(i, 1, N) { ans += (ll)depth[i].size() * A[i]; }
    if (ans > 0)
        cout << '+';
    else if (ans < 0)
        cout << '-';
    else {
        if (s > 0)
            cout << '+';
        else if (s < 0)
            cout << '-';
        else
            cout << '0';
    }
    cout << endl;
}
