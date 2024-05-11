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
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
        g.add_edge(b, a);
    }
    vi group(N, -1);
    vvi group_cnt;
    rep(i, N) {
        if (group[i] != -1) continue;
        group_cnt.push_back({});
        queue<int> q;
        q.push(i);
        group[i] = 0;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            group_cnt.back().push_back(v);
            int gp = group[v];
            for (auto e : g[v]) {
                int u = *e.to;
                if (group[u] == gp) {
                    cout << 0 << endl;
                    return 0;
                }
                if (group[u] != -1) continue;
                group[u] = gp ^ 1;
                q.push(u);
            }
        }
    }
    if (group_cnt.size() == 1) {
        map<int, ll> cnt;
        rep(i, N) { cnt[group[i]]++; }
        ll ans = 0;
        rep(i, N) { ans += N - cnt[group[i]] - g[i].size(); }
        cout << ans / 2 << endl;
    } else {
        ll ans = N * (N - 1) / 2 - M;
        for (auto gr : group_cnt) {
            map<int, ll> cnt;
            for (auto v : gr) {
                cnt[group[v]]++;
            }
            ll b = cnt[0];
            ll w = cnt[1];
            ans -= b * (b - 1) / 2 + w * (w - 1) / 2;
        }
        cout << ans << endl;
    }
}
