#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, M;
    cin >> N >> M;
    Graph g(N), g_rev(N);
    rep(M) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
        g_rev.add_edge(b, a);
    }

    auto scc = g.scc(g_rev);

    ll ans = 0;
    rep(i, N) {
        if (scc.root(i) != i) continue;
        ll siz = scc.size(i);
        ans += siz * (siz - 1LL) / 2LL;
    }

    cout << ans << endl;
}
