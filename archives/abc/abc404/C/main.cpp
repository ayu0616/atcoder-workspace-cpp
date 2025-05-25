#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    if (N != M) {
        cout << "No" << endl;
        return 0;
    }
    vvi g(N);
    hassaku::UnionFind<ll> uf(N);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        uf.unite(a, b);
    }
    if (uf.groups() != 1) {
        cout << "No" << endl;
        return 0;
    }

    vi cnt(N);
    rep(i, N) {
        for (auto v : g[i]) {
            cnt[v]++;
        }
    }
    rep(i, N) {
        if (cnt[i] != 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    // vb visited(N, false);
    // function<bool(int, int)> dfs;
    // dfs = [&](int v, int p) {
    //     visited[v] = true;
    //     bool res = true;
    //     for (auto u : g[v]) {
    //         if (visited[u] && u != p && u != 0) {
    //             return false;
    //         }
    //         if (visited[u]) continue;
    //         res &= dfs(u, v);
    //     }
    //     visited[v] = false;
    //     return res;
    // };
    // bool res = dfs(0, -1);
    // if (res) {
    //     cout << "Yes" << endl;
    // } else {
    //     cout << "No" << endl;
    // }
}
