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

struct Random {
    mt19937 mt;

    Random() { mt.seed(616); }

    double operator()() { return (double)mt() / mt.max(); }

    int random_int(int min, int max) { return min + (int)(mt() * (max - min + 1.0) / (1.0 + mt.max())); }

    template <typename T>
    T random_choice(vector<T> &v) {
        int idx = random_int(0, v.size() - 1);
        return v[idx];
    }
};

Random rnd;

vector<vector<vector<pii>>> pos_memo;

struct State {
    vi order;
    vpii ans;
    int score = -1;

    State() { init(); }

    void init() {
        order.push_back(0);
        set<int> used;
        used.insert(0);
        int cand = 0;
        int max_len = 0;
        while (used.size() < M) {
            int cur = order.back();
            rep(i, M) {
                if (used.find(i) != used.end()) continue;
                if (cur == i) continue;
                rep(i, 5 - max_len) {
                    string s1 = t[cur].substr(t[cur].size() - 5 + i);
                    string s2 = t[i].substr(0, 5 - i);
                    if (s1 == s2) {
                        cand = i;
                        max_len = 5 - i;
                        break;
                    }
                }
            }
            while (used.find(cand) != used.end()) {
                cand = rnd.random_int(0, M - 1);
            }
            order.push_back(cand);
            used.insert(cand);
        }
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
            if (!ok) s += t[order[i]];
        }
        for (auto c : s) {
            int min_d = 1e9;
            int tmp_i, tmp_j;
            if (pos_memo[si][sj][c - 'A'].first != -1) {
                tmp_i = pos_memo[si][sj][c - 'A'].first;
                tmp_j = pos_memo[si][sj][c - 'A'].second;
            } else {
                for (auto p : positions[c]) {
                    int d = abs(p.first - si) + abs(p.second - sj);
                    if (d < min_d) {
                        min_d = d;
                        tmp_i = p.first;
                        tmp_j = p.second;
                    }
                }
                pos_memo[si][sj][c - 'A'] = {tmp_i, tmp_j};
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

    pos_memo.resize(N, vector<vector<pii>>(N, vector<pii>(26, {-1, -1})));

    State state;

    while (true) {
        if (time.is_over(TIME_LIMIT)) break;
        int i = rnd.random_int(0, M - 1);
        int j = rnd.random_int(0, M - 1);
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
