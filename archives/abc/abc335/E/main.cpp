#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

// @brief トポロジカルソート
// @return トポロジカルソートされた頂点のリスト
vi topological_sort(vvi &g) {
    int n = g.size();
    vi res;
    vb used(n, false);
    function<void(int)> dfs = [&](int v) {
        used[v] = true;
        for (auto u : g[v]) {
            if (!used[u]) dfs(u);
        }
        res.push_back(v);
    };
    rep(i, n) {
        if (!used[i]) dfs(i);
    }
    reverse(all(res));
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    vi A(N, 0);
    rep(i, N) cin >> A[i];
    vvi g(N);
    UnionFind merged(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        u = merged.root(u);
        v = merged.root(v);
        if (A[u] < A[v]) g[u].push_back(v);
        if (A[u] > A[v]) g[v].push_back(u);
        if (A[u] == A[v]) {
            merged.unite(u, v);
            int mv = merged.root(v);
            if (u == mv) u = v;
            copy(all(g[u]), back_inserter(g[mv]));
        }
    }

    auto sorted = topological_sort(g);

    vi ans(N, 0);
    int cur = merged.root(0);
    ans[cur] = 1;
    auto cur_it = find(all(sorted), cur);
    sorted = vi(cur_it, sorted.end());
    for (auto v : sorted) {
        for (auto u : g[v]) chmax(ans[u], ans[v] + 1);
    }
    int goal = N - 1;
    goal = merged.root(goal);
    cout << ans[goal] << endl;
}
