#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl X(N), A(N);
    cin >> X >> A;
    if (K == 0) {
        cout << A << endl;
        return 0;
    }
    rep(i, N) { X[i]--; }

    Graph g(N);
    vb visited(N);
    UnionFind<int> uf(N);
    rep(i, N) {
        int v = i;
        while (!visited[v]) {
            visited[v] = true;
            g.add_edge(v, X[v]);
            uf.unite(v, X[v]);
            v = X[v];
        }
    }
    vl ans(N);
    vi loop_idx(N, -1);
    map<int, vi> loop_map;
    rep(i, N) {
        vb visited(N);
        int v = i;
        while (!visited[v]) {
            visited[v] = true;
            v = X[v];
        }
        int idx = 0;
        while (loop_idx[v] == -1) {
            loop_idx[v] = idx++;
            loop_map[uf.root(i)].push_back(v);
            v = X[v];
        }
    }
    rep(i, N) {
        int depth = 0;
        int v = i;
        while (loop_idx[v] == -1 && depth < K) {
            v = X[v];
            depth++;
        }
        if (depth == K) {
            ans[i] = v;
        } else {
            int loop_start = loop_idx[v];
            int loop_size = loop_map[uf.root(i)].size();
            int idx = (K - depth + loop_start) % loop_size;
            ans[i] = A[loop_map[uf.root(i)][idx]];
        }
    }
    cout << ans << endl;
}
