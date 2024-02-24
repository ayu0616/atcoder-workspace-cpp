#include <queue>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr char Unreachable[] = "Unreachable";

struct Train {
    ll l;
    ll d;
    ll k;
    ll c;
    int A;
    int B;
};

int main() {
    cout << fixed << setprecision(18);
    int N, M;
    cin >> N >> M;
    vector<Train> trains(M);
    rep(i, M) {
        cin >> trains[i].l >> trains[i].d >> trains[i].k >> trains[i].c >> trains[i].A >> trains[i].B;
        trains[i].A--;
        trains[i].B--;
    }
    vector<vector<Train>> rev_g(N);
    rep(i, M) { rev_g[trains[i].B].push_back(trains[i]); }
    vector<ll> dist(N, -LL_INF);
    dist[N - 1] = LL_INF;
    priority_queue<pair<ll, int>> pq;
    pq.push({dist[N - 1], N - 1});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d < dist[u]) continue;
        for (auto &train : rev_g[u]) {
            ll next = train.A;
            ll start = d - train.c;
            if (start < train.l) {
                dist[next] = -LL_INF;
                continue;
            }
            ll next_start = min(start - (start - train.l) % train.d, train.l + (train.k - 1) * train.d);
            if (dist[next] < next_start) {
                dist[next] = next_start;
                pq.push({dist[next], next});
            }
        }
    }
    rep(i, N - 1) {
        if (dist[i] == -LL_INF) {
            cout << Unreachable << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
}
