#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
// #include "hassaku/binary-search.hpp"
// #include "hassaku/cumulative-sum.hpp"
// #include "hassaku/doubly-linked-list.hpp"
// #include "hassaku/gcd.hpp"
// #include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M, E;
    cin >> N >> M >> E;
    vpii edges(E);
    rep(i, E) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        edges[i] = {a, b};
    }
    ll Q;
    cin >> Q;
    vi X(Q);
    cin >> X;
    rep(i, Q) X[i]--;
    reverse(all(X));
    set<int> Xset(all(X));
    vl w(N + M, 0);
    rep(i, N) w[i] = 1;
    hassaku::WeightedUnionFind<> uf(N + M, w);
    vvi G(N + M);
    rep(i, E) {
        if (Xset.count(i)) continue;
        auto [a, b] = edges[i];
        G[a].push_back(b);
        G[b].push_back(a);
        uf.unite(a, b);
    }
    vb is_ok(N+M, false);
    rep(i, M) { is_ok[i + N] = true; }
    vb used(N + M, false);
    auto dfs = [&](auto &&f, int v) -> void {
        used[v] = true;
        is_ok[v] = true;
        for (auto u : G[v]) {
            if (used[u]) continue;
            f(f, u);
        }
    };
    rep(i, M) {
        if (!used[N + i]) {
            dfs(dfs, N + i);
        }
    }
    int cur = 0;
    rep(i, N) {
        if (is_ok[i]) {
            cur++;
        }
    }
    vi ans(Q);
    rep(i, Q) {
        ans[i] = cur;
        auto [a, b] = edges[X[i]];
        int aroot = uf.root(a);
        int broot = uf.root(b);
        if (is_ok[aroot] && !is_ok[broot]) {
            cur += uf.weight(b);
            is_ok[broot] = true;
        } else if (!is_ok[aroot] && is_ok[broot]) {
            cur += uf.weight(a);
            is_ok[aroot] = true;
        }
        uf.unite(a, b);
    }
    reverse(all(ans));
    rep(i, Q) { cout << ans[i] << endl; }
}
