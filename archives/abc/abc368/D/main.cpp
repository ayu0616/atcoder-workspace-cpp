#include <functional>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vb includs;

void solve(int v, vvi &G, vb &visited, vb &removed, vi &V) {
    visited[v] = true;
    for (int u : G[v]) {
        if (visited[u]) continue;
        solve(u, G, visited, removed, V);
    }
    if (includs[v]) return;
    int cnt = 0;
    for (int u : G[v]) {
        if (removed[u]) continue;
        cnt++;
        if (cnt > 1) break;
    }
    if (cnt == 1) {
        removed[v] = true;
    }
}

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vvi G(N);
    rep(i, N - 1) {
        ll a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vi V(K);
    cin >> V;
    rep(i, K) V[i]--;
    includs.resize(N);
    for (int v : V) includs[v] = true;
    vb visited(N), removed(N);
    solve(V[0], G, visited, removed, V);
    int ans = 0;
    for (bool r : removed) {
        if (!r) ans++;
    }
    cout << ans << endl;
}
