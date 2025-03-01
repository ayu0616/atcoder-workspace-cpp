#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct State {
    int v;
    ll dist;
    int graph;

    inline bool operator<(const State other) const { return dist < other.dist; }
    inline bool operator>(const State other) const { return dist > other.dist; }
};

// int main() {
//     cout << fixed << setprecision(18);
//     ll N, M, X;
//     cin >> N >> M >> X;
//     vvi Graph(N), Graph_rev(N);
//     rep(i, M) {
//         int u, v;
//         cin >> u >> v;
//         u--, v--;
//         Graph[u].push_back(v);
//         Graph_rev[v].push_back(u);
//     }
//     vvl dist(N, vl(2, LL_INF));
//     dist[0][0] = 0;
//     priority_queue<State, vector<State>, greater<State>> que;
//     que.push({0, 0, 0});
//     array<vvi, 2> graphs = {Graph, Graph_rev};
//     while (!que.empty()) {
//         auto state = que.top();
//         que.pop();
//         if (dist[state.v][state.graph] < state.dist) continue;
//         for (auto v : graphs[state.graph][state.v]) {
//             if (dist[v][state.graph] > dist[state.v][state.graph] + 1) {
//                 dist[v][state.graph] = dist[state.v][state.graph] + 1;
//                 que.push({v, dist[v][0], state.graph});
//             }
//         }
//         if (dist[state.v][1 - state.graph] > dist[state.v][state.graph] + X) {
//             dist[state.v][1 - state.graph] = dist[state.v][state.graph] + X;
//             que.push({state.v, dist[state.v][1 - state.graph], 1 - state.graph});
//         }
//     }
//     cout << min(dist[N - 1]) << endl;
// }

int main() {
    cout << fixed << setprecision(18);
    ll N, M, X;
    cin >> N >> M >> X;
    vector<vector<pll>> Graph(2 * N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        Graph[u].push_back({v, 1});
        Graph[v+N].push_back({u+N, 1});
    }
    rep(i, N) {
        Graph[i].push_back({i + N, X});
        Graph[i + N].push_back({i, X});
    }
    vl dist(2 * N, LL_INF);
    dist[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> que;
    que.push({0, 0});
    while (!que.empty()) {
        auto [d, v] = que.top();
        que.pop();
        if (dist[v] < d) continue;
        for (auto [to, cost] : Graph[v]) {
            if (dist[to] > dist[v] + cost) {
                dist[to] = dist[v] + cost;
                que.push({dist[to], to});
            }
        }
    }
    cout << min(dist[N - 1], dist[N + N - 1]) << endl;
}
