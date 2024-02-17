#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N;
    cin >> N;
    vi A(N), B(N), X(N);
    rep(i, N - 1) { cin >> A[i] >> B[i] >> X[i]; }

    Graph g(N);
    rep(i, N - 1) {
        g.add_edge(i, i + 1, A[i]);
        g.add_edge(i, X[i] - 1, B[i]);
    }

    cout << g.dyjkstra(0)[N - 1] << endl;
}
