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
    set<ll> level1, level2, level3;
    vb visited(N, false);
    rep(i, N) {
        if (g[i].size() == 1) {
            visited[i] = true;
            visited[g[i][0]] = true;
            for (auto l2 : g[g[i][0]]) {
                if(!visited[l2]) {
                    level3.insert(l2);
                    visited[l2] = true;
                }
            }
        }
    }
    ll ans = LL_INF;
    {
        ll max_reg = 0;
        rep(i, N) {
            if (max_reg < g[i].size()) {
                max_reg = g[i].size();
            }
        }
        chmin(ans, N - max_reg - 1);
    }
    for (auto l3 : level3) {
        ll c = 0;
        map<ll, ll> mp;
        set<ll> se;
        for (auto l2 : g[l3]) {
            if (g[l2].size() > 1) {
                se.insert(g[l2].size());
                mp[g[l2].size()]++;
            }
        }
        ll cnt = 0;
        auto it = se.rbegin();
        while (it != se.rend()) {
            cnt += mp[*it];
            chmax(c, cnt * (*it));
            it++;
        }
        chmin(ans, N - c - 1);
    }
    cout << ans << endl;
}
