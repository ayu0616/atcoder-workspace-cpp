#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct E {
    ll id, from, to, cost;
};

bool operator<(const E& a, const E& b) {
    return a.id < b.id;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, M, Q;
    cin >> N >> M >> Q;
    vector<set<int>> G(N);
    vector<E> edges;
    rep(i, M) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].insert(i);
        G[b].insert(i);
        edges.push_back({i, a, b, c});
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i;
            cin >> i;
            i--;
            E e = edges[i];
            G[e.from].erase(i);
            G[e.to].erase(i);
        } else {
            int x, y;
            cin >> x >> y;
            x--, y--;
            vector<ll> dist(N, LL_INF);
            dist[x] = 0;
            priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
            pq.push({0, x});
            while (!pq.empty()) {
                auto [d, v] = pq.top();
                pq.pop();
                if (dist[v] < d) continue;
                for (auto& eid : G[v]) {
                    E e = edges[eid];
                    if (dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        pq.push({dist[e.to], e.to});
                    }
                }
            }
            if (dist[y] == LL_INF) {
                cout << -1 << endl;
            } else {
                cout << dist[y] << endl;
            }
        }
    }
}
