#include <cassert>
#include <queue>
#include <vector>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Train {
    ll A, B, S, T, id;
};

int main() {
    cout << fixed << setprecision(18);
    time_t start = clock();
    ll N, M, X0;
    cin >> N >> M >> X0;
    vector<Train> trains(M);
    vector<vector<Train>> stations(N);
    rep(i, M) {
        Train train;
        cin >> train.A >> train.B >> train.S >> train.T;
        train.id = i;
        train.A--, train.B--;
        trains[i] = train;
        stations[train.A].push_back(train);
    }
    vl X(M, 0);
    X[0] = X0;
    deque<ll> que;
    que.push_back(0);
    while (!que.empty() && clock() - start < 1.9 * CLOCKS_PER_SEC) {
        auto t = que.front();
        que.pop_front();
        Train train = trains[t];
        for (Train next_train : stations[train.B]) {
            int nt = next_train.id;
            if (nt == 0) {
                continue;
            }
            if (train.T > next_train.S) {
                continue;
            }
            if (train.T + X[t] <= next_train.S + X[nt]) {
                continue;
            }
            X[nt] = train.T + X[t] - next_train.S;
            que.push_back(nt);
        }
    }
    cout << vl(X.begin() + 1, X.end()) << endl;
}
