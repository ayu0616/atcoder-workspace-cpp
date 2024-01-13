#include "../../lib.hpp"

int N, M, si, sj;
vs A, t;
map<char, vpii> positions;
constexpr int TIME_LIMIT = 1950;

struct Time {
    chrono::system_clock::time_point start;
    Time() { start = chrono::system_clock::now(); }

    // 経過時間をミリ秒で取得
    ll get() {
        auto end = chrono::system_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }

    bool is_over(ll limit) { return get() > limit; }
};

struct State {
    vi order;
    vpii ans;
    int score = -1;

    State() { init(); }

    void init() {
        order.resize(M);
        rep(i, M) order[i] = i;
        ans = calc_ans();
    }

    vpii calc_ans() {
        vpii _ans;
        string s = t[order[0]];
        rep(i, 1, M) {
            bool ok = false;
            rep(j, 5) {
                string s1 = s.substr(s.size() - 5 + j);
                string s2 = t[order[i]].substr(0, 5 - j);
                if (s1 == s2) {
                    s += t[order[i]].substr(5 - j);
                    ok = true;
                    break;
                }
            }
            if (!ok)
            s += t[order[i]];
        }
        for (auto c : s) {
            int min_d = 1e9;
            int tmp_i, tmp_j;
            for (auto p : positions[c]) {
                int d = abs(p.first - si) + abs(p.second - sj);
                if (d < min_d) {
                    min_d = d;
                    tmp_i = p.first;
                    tmp_j = p.second;
                }
            }
            _ans.emplace_back(tmp_i, tmp_j);
            si = tmp_i, sj = tmp_j;
        }
        return _ans;
    }

    int calc_score() {
        if (score != -1) return score;
        int cost = 0;
        cost += abs(ans[0].first - si) + abs(ans[0].second - sj) + 1;
        rep(i, ans.size() - 1) { cost += abs(ans[i].first - ans[i + 1].first) + abs(ans[i].second - ans[i + 1].second) + 1; }
        return score = 10000 - cost;
    }

    State next(int i, int j) {
        State res = *this;
        swap(res.order[i], res.order[j]);
        res.ans = res.calc_ans();
        res.score = -1;
        return res;
    }
};

int main() {
    cin >> N >> M >> si >> sj;
    A.resize(N), t.resize(M);
    cin >> A >> t;

    Time time;

    rep(i, N) rep(j, N) { positions[A[i][j]].emplace_back(i, j); }

    State state;

    while (true) {
        if (time.is_over(TIME_LIMIT)) break;
        int i = rand() % M;
        int j = rand() % M;
        if (i == j) continue;
        State next = state.next(i, j);
        if (next.calc_score() > state.calc_score()) {
            state = next;
        }
    }

    vpii ans = state.ans;
    assert(ans.size() <= 5000);
    cerr << state.calc_score() << endl;
    rep(i, ans.size()) cout << ans[i] << endl;
}
