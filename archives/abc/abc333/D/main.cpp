#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
vector<int> w;
vb seen;

void dfs(Graph &g, int v) {
    seen[v] = true;
    for (auto nv : g[v]) {
        if (seen[*nv.to]) continue;
        dfs(g, *nv.to);
        w[v] += w[*nv.to];
    }
}

int main() {
    int N;
    cin >> N;
    Graph g(N);
    rep(i, N - 1) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
        g.add_edge(v, u);
    }

    w.assign(N, 1);
    seen.assign(N, false);
    dfs(g, 0);
    vi ans;
    for (auto nv : g[0]) {
        ans.push_back(w[*nv.to]);
    }
    sort(all(ans));
    cout << accumulate(ans.begin(), ans.end() - 1, 0) + 1 << endl;
}
