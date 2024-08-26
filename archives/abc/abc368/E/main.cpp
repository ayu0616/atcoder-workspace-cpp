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

struct Event {
    ll time, type, station, train;

    bool operator<(const Event &rhs) const {
        if (time == rhs.time) {
            return type < rhs.type;
        }
        return time < rhs.time;
    }
};

int main() {
    cout << fixed << setprecision(18);
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
    vl X(M, 0), last(N, 0);
    X[0] = X0;
    vector<Event> events;
    rep(i, M) {
        events.push_back({trains[i].S, 1, trains[i].A, i});
        events.push_back({trains[i].T, 0, trains[i].B, i});
    }
    sort(all(events));
    for (auto &&event : events) {
        Train train = trains[event.train];
        if (event.type == 1) {
            if (last[event.station] > train.S + X[event.train]) {
                X[event.train] += last[event.station] - train.S - X[event.train];
            }
        } else {
            chmax(last[train.B], train.T + X[event.train]);
        }
    }
    cout << vl(X.begin() + 1, X.end()) << endl;
}
