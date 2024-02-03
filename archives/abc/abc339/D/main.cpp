#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct State {
    pii p1, p2;
    int cnt;

    int dist() const { return abs(p1.first - p2.first) + abs(p1.second - p2.second); }

    bool operator<(const State& other) const { return cnt + dist() > other.cnt + other.dist(); }

    bool is_goal() const { return p1.first == p2.first && p1.second == p2.second; }
};

int main() {
    int N;
    cin >> N;
    vs S(N);
    cin >> S;
    pii p1, p2;
    p1 = p2 = {-1, -1};
    rep(i, N) rep(j, N) {
        if (S[i][j] == 'P') {
            if (p1.first == -1) {
                p1 = {i, j};
            } else {
                p2 = {i, j};
            }
        }
    }
    priority_queue<State> que;
    que.push({p1, p2, 0});
    set<pair<pii, pii>> visited;
    while (!que.empty()) {
        State cur = que.top();
        que.pop();
        if (cur.is_goal()) {
            cout << cur.cnt << endl;
            return 0;
        }
        if (visited.count({cur.p1, cur.p2})) {
            continue;
        }
        visited.insert({cur.p1, cur.p2});
        rep(i, 4) {
            int nx1 = cur.p1.first + dx4[i];
            int ny1 = cur.p1.second + dy4[i];
            int nx2 = cur.p2.first + dx4[i];
            int ny2 = cur.p2.second + dy4[i];
            if (nx1 < 0 || nx1 >= N || ny1 < 0 || ny1 >= N || S[nx1][ny1] == '#') {
                nx1 = cur.p1.first;
                ny1 = cur.p1.second;
            }
            if (nx2 < 0 || nx2 >= N || ny2 < 0 || ny2 >= N || S[nx2][ny2] == '#') {
                nx2 = cur.p2.first;
                ny2 = cur.p2.second;
            }
            // 移動なしならスキップ
            if (nx1 == cur.p1.first && ny1 == cur.p1.second && nx2 == cur.p2.first && ny2 == cur.p2.second) {
                continue;
            }
            que.push({{nx1, ny1}, {nx2, ny2}, cur.cnt + 1});
        }
    }
    cout << -1 << endl;
}
