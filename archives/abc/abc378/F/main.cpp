#include <vector>
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
    ll N;
    cin >> N;
    Graph g(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    ll ans = 0;
    UnionFind<int> uf(N);
    rep(i, N) {
        if (g[i].size() != 3) continue;
        for (auto& e : g[i]) {
            int v = e.to->id;
            if (g[v].size() != 3) continue;
            uf.unite(i, v);
        }
    }
    vector<set<int>> cnt(N);
    rep(i, N) {
        if (g[i].size() != 3) continue;
        int root = uf.root(i);
        for (auto& e : g[i]) {
            int v = e.to->id;
            if (g[v].size() == 2) {
                cnt[root].insert(v);
            }
        }
    }
    rep(i, N) {
        const ll siz = cnt[i].size();
        ans += siz * (siz - 1) / 2;
    }
    cout << ans << endl;
}
