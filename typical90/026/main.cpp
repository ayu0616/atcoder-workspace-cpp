#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    Graph g(N);
    rep(i, N - 1) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        g.add_edge(A, B);
        g.add_edge(B, A);
    }
    set<int> odd, even;
    vb visited(N, false);

    function<void(int, int)> dfs;
    dfs = [&](int v, int depth) {
        visited[v] = true;
        if (depth % 2 == 0)
            even.insert(v);
        else
            odd.insert(v);
        for (auto e : g[v]) {
            int u = e.to->id;
            if (!visited[u]) dfs(u, depth + 1);
        }
    };

    dfs(0, 0);
    if (odd.size() < even.size()) swap(odd, even);
    rep(i, N / 2) {
        cout << *odd.begin() + 1 << " \n"[i == N / 2 - 1];
        odd.erase(odd.begin());
    }
}
