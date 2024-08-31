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
    Graph g(N);
    vector<tuple<ll, ll, ll>> edges(M);
    rep(i, M) {
        ll u, v, t;
        cin >> u >> v >> t;
        u--, v--;
        edges[i] = {u, v, t};
    }
    map<pll, ll> mp;
    rep(i, M) {
        auto [u, v, t] = edges[i];
        if (mp.find({u, v}) == mp.end()) {
            mp[{u, v}] = t;
        } else {
            chmin(mp[{u, v}], t);
        }
    }
    for (auto [k, val] : mp) {
        auto [u, v] = k;
        g.add_edge(u, v, val);
        g.add_edge(v, u, val);
    }
    vvl dist = g.warshall_floyd();
    ll Q;
    cin >> Q;
    while (Q--) {
        ll K;
        cin >> K;
        vi B(K);
        cin >> B;
        rep(i, K) B[i]--;
        ll ans = LL_INF;
        do {
            for (ll S = 0; S < 1 << K; S++) {
                ll d = 0;
                int cur = 0;
                rep(i, K) {
                    auto [u, v, t] = edges[B[i]];
                    if (S >> i & 1) {
                        d += dist[cur][u] + t;
                        cur = v;
                    } else {
                        d += dist[cur][v] + t;
                        cur = u;
                    }
                }
                d += dist[cur][N - 1];
                chmin(ans, d);
            }
        } while (next_permutation(all(B)));
        cout << ans << endl;
    }
}
