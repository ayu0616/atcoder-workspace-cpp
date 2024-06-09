#include <numeric>
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
    vl a(N);
    cin >> a;
    for (auto& ai : a) {
        ai--;
    }
    UnionFind<ll> uf(N);
    vb visited(N, false);
    rep(i, N) {
        if (visited[i]) {
            continue;
        }
        vb vis(N, false);
        ll v = i;
        while (!vis[v]) {
            vis[v] = true;
            v = a[v];
        }
        ll gv = v;
        v = a[v];
        while (v != gv) {
            visited[v] = true;
            uf.unite(v, gv);
            v = a[v];
        }
    }

    vector<ll> ans(N, 0);
    rep(i, N) { ans[i] = uf.size(i); }
    visited = vb(N, false);
    rep(i, N) visited[i] = ans[i] > 1 || i == a[i];
    function<ll(ll)> solve = [&](ll i) {
        if (visited[i]) {
            return ans[i];
        }
        visited[i] = true;
        ans[i] += solve(a[i]);
        return ans[i];
    };

    rep(i, N) { solve(i); }
    ll res = 0;
    rep(i, N) { res += ans[i]; }
    cout << res << endl;
}
