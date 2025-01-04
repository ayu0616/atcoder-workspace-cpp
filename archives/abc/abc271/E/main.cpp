#include <algorithm>
#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using tp = tuple<ll, ll, ll>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M, K;
    cin >> N >> M >> K;
    Graph g(N);
    vector<Edge> edges;
    rep(i, M) {
        ll A, B, C;
        cin >> A >> B >> C;
        A--, B--;
        g.add_edge(A, B, C);
        edges.emplace_back(A, B, C);
    }
    vl E(K);
    cin >> E;
    rep(i, K) E[i]--;

    ll dp[N];
    fill(dp, dp + N, LL_INF);
    dp[0] = 0;
    rep(i, K) {
        // auto prev = dp;
        auto e = edges[E[i]];
        chmin(dp[e.to->id], dp[e.from->id] + e.cost);
    }
    if (dp[N - 1] == LL_INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[N - 1] << endl;
}
