#include <cassert>
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
    Graph G(N);
    rep(i, M) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        G.add_edge(a, b, w);
        G.add_edge(b, a, -w);
    }
    vb visited(N, false);
    vl ans(N, 0);
    rep(i, N) {
        if (visited[i]) {
            continue;
        }
        queue<ll> q;
        q.push(i);
        while (!q.empty()) {
            ll cur = q.front();
            q.pop();
            visited[cur] = true;
            for (auto& e : G[cur]) {
                int to = *e.to;
                if (visited[to]) {
                    continue;
                }
                ans[to] = ans[cur] + e.cost;
                q.push(to);
            }
        }
    }

// check
#ifdef HASSAKU_DEBUG
    {
        rep(i, N) {
            for (auto& e : G[i]) {
                int to = *e.to;
                assert(ans[to] - ans[i] == e.cost);
            }
        }
    }
#endif

    cout << ans << endl;
}
