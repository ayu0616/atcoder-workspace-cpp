#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct E {
    int to, w;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vector<vector<E>> graph(N);
    rep(i, M) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    ll X = (1LL << 30) - 1;
    for (int i = 29; i >= 0; i--) {
        X = X ^ (1LL << i);
        hassaku::UnionFind<> uf(N);
        rep(v, N) {
            for (auto e : graph[v]) {
                if ((e.w | X) == X) {
                    uf.unite(v, e.to);
                }
            }
        }
        if (!uf.same(0, N - 1)) {
            X = X ^ (1LL << i);
        }
    }
    cout << X << endl;
}
