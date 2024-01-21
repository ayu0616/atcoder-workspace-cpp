#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N);
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        g.add_edge(A, B, C);
        g.add_edge(B, A, C);
    }
    vl from_zero = g.dyjkstra(0);
    vl from_n = g.dyjkstra(N - 1);
    rep(k, N) { cout << from_zero[k] + from_n[k] << endl; }
}
