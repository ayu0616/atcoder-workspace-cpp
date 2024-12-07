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
    ll N, M, K;
    cin >> N >> M >> K;
    Graph G(N);
    vl A(K), B(K);
    rep(i, M) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        G.add_edge(u, v, w);
        G.add_edge(v, u, w);
    }
    cin>>A>>B;
}
