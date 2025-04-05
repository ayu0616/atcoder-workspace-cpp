#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Score {
    ll dist, cost;
    Score(ll dist, ll cost) : dist(dist), cost(cost) {}
    Score() : dist(0), cost(0) {}

    bool operator<(Score& other) const {
        if (dist != other.dist) return dist > other.dist;
        return cost > other.cost;
    }

    bool operator>(Score& other) const {
        if (dist != other.dist) return dist < other.dist;
        return cost < other.cost;
    }
};

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl C(N), X(N);
    cin >> C >> X;
    vl v(N, -1);
    priority_queue<pair<Score, ll>> pq;
    Score init(N, 0);
    vector<Score> s(N + 1);
    for (int i = 0; i <= N; i++) {
        s[i] = Score(N, LL_INF);
    }
    pq.push({init, 0});
    while (!pq.empty()) {
        auto [score, pos] = pq.top();
        pq.pop();
        auto [dist, cost] = score;
        if (pos == N) {
            cout << cost << endl;
            return 0;
        }
        if (v[pos] == C[pos]) continue;
        for (int i = 1; pos + i - 1 < N; i++) {
            ll new_cost = cost + X[i] + i;
            vl new_v = v;
            for (int j = pos; j < pos + i; j++) {
                new_v[j] = C[i];
            }
            ll new_dist = dist + abs(X[i] - X[pos]);
            Score new_score(new_dist, new_cost);
            if (s[pos + 1] < new_score) {
                pq.push({new_score, pos + 1});
                s[pos + 1] = new_score;
            }
        }
    }
}
