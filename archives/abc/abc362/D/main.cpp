#include <queue>
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
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;
    Graph g(N);
    rep(i, M) {
        int u, v;
        ll b;
        cin >> u >> v >> b;
        --u, --v;
        g.add_edge(u, v, b + A[v]);
        g.add_edge(v, u, b + A[u]);
    }
    vl ans = g.dyjkstra(0);
    for (auto &v : ans) v += A[0];
    cout << vl(ans.begin() + 1, ans.end()) << endl;
}
