#include <ctime>

#include "hassaku/union-find.hpp"
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct E {
    ll from, to, cost, id;
    E() {}
    E(ll from, ll to, ll cost, ll id) : from(from), to(to), cost(cost), id(id) {}
};

int main() {
    cout << fixed << setprecision(18);
    time_t start = time(NULL);
    ll N, M;
    cin >> N >> M;
    vector<E> edges(M);
    vector<vector<E>> G(N);
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges[i] = {a, b, c, i};
        G[a].push_back(edges[i]);
    }
    hassaku::UnionFind<ll> uf(N);
    rep(i, N) {
        foreach (e, G[i]) {
            if (uf.same(e.from, e.to)) {
                continue;
            }
            uf.unite(e.from, e.to);
        }
    }
    if (!uf.same(0, N - 1)) {
        cout << -1 << endl;
        return 0;
    }
    ll ans = LL_INF;
    map<pair<ll, ll>, bool> used;
    deque<pair<ll, ll>> q;
    q.push_back({0, 0});
    while (!q.empty()) {
        auto [v, cost] = q.front();
        q.pop_front();
        if (used[{v, cost}]) continue;
        used[{v, cost}] = true;
        if (v == N - 1) {
            ans = min(ans, cost);
        }
        foreach (e, G[v]) {
            q.push_back({e.to, cost ^ e.cost});
        }
    }
    if (ans == LL_INF) {
        ans = -1;
    }
    cout << ans << endl;
}