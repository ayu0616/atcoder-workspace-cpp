#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int N, d_sum = 0;
constexpr int L_MAX = 1e5, N_MAX = 40;
constexpr char DIRS[] = "RDLU";
map<char, int> DIR_IDX = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}};
vs h, v;
vvi d;  // 汚れやすさ

struct Square {
    int x, y;
    Square *prev = nullptr, *next = nullptr;
    int dirty;  // 汚れやすさ
    Square(int x, int y) : x(x), y(y) { dirty = d[y][x]; }

    // 汚れやすさで比較
    bool operator<(const Square &s) const { return dirty < s.dirty; }

    Square *move(char dir) {
        int dx = dx4[DIR_IDX[dir]], dy = dy4[DIR_IDX[dir]];
        int nx = x + dx, ny = y + dy;
        auto s = new Square(nx, ny);
        // s->prev = this;
        // next = s;
        return s;
    }

    static void join(Square *s1, Square *s2) {
        s1->next = s2;
        s2->prev = s1;
    }
};

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

// pathは移動後のマス
ll calc_score(Square *begin) {
    int L = 0;
    vvi last_turns(N, vi(N, -1));
    // 1週目
    auto s = begin;
    while (s->next != nullptr) {
        last_turns[s->y][s->x] = L;
        ++L;
        s = s->next;
    }
    vvi cur_d(N, vi(N, 0));
    rep(i, N) rep(j, N) cur_d[i][j] = d[i][j] * (L - 1 - last_turns[i][j]);
    cur_d[begin->y][begin->x] = 0;
    // 2週目
    ll score = 0, accum_score = 0;
    rep(i, N) rep(j, N) score += cur_d[i][j];
    last_turns.assign(N, vi(N, 0));
    s = begin->next;
    int l = 1;
    while (s->next != nullptr) {
        int x = s->x, y = s->y;
        score += d_sum - d[y][x] * (l - last_turns[y][x]) - cur_d[y][x];
        accum_score += score;
        last_turns[y][x] = l;
        cur_d[y][x] = 0;
        ++l;
        s = s->next;
    }
    return accum_score / (L - 1);
}

int dir(int dx, int dy) {
    if (dx == 1)
        return 0;
    else if (dx == -1)
        return 2;
    else if (dy == 1)
        return 1;
    else if (dy == -1)
        return 3;
    else
        return -1;
}

// pathから移動方向文字列を生成する
string path_to_ans(Square *begin) {
    auto cur = begin;
    string ans = "";
    while (cur->next != nullptr) {
        int dx = cur->next->x - cur->x, dy = cur->next->y - cur->y;
        int w = dir(dx, dy);
        ans += DIRS[w];
        cur = cur->next;
    }
    return ans;
}

// 現在地からdir方向に移動できるか
bool can_move(int x, int y, char dir) {
    switch (dir) {
        case 'U':
            if (y == 0) return false;
            return h[y - 1][x] == '0';
            break;
        case 'D':
            if (y == N - 1) return false;
            return h[y][x] == '0';
            break;
        case 'L':
            if (x == 0) return false;
            return v[y][x - 1] == '0';
            break;
        case 'R':
            if (x == N - 1) return false;
            return v[y][x] == '0';
            break;
        default:
            return false;
            break;
    }
}

vector<vector<vector<Square *>>> grid(N_MAX, vector<vector<Square *>>(N_MAX));

vvb visited(N_MAX, vb(N_MAX, false));
set<int> visited_set;
Square *last = nullptr;
void dfs(Square *s) {
    int x = s->x, y = s->y;
    visited[y][x] = true;
    vpii nexts;
    rep(i, 4) {
        char dir = DIRS[i];
        if (!can_move(x, y, dir)) continue;
        int dx = dx4[i], dy = dy4[i];
        int nx = x + dx, ny = y + dy;
        if (visited[ny][nx]) continue;
        nexts.emplace_back(nx, ny);
    }
    sort(all(nexts), [&](pii p1, pii p2) { return d[p1.second][p1.first] > d[p2.second][p2.first]; });
    for (auto [nx, ny] : nexts) {
        // 行き
        Square *s = new Square(nx, ny);
        Square::join(last, s);
        visited_set.insert(ny * N + nx);
        last = s;
        grid[ny][nx].emplace_back(s);
        dfs(s);
        // 帰り TODO: 帰りは汚れやすさの低い頂点に訪れる必要がない
        if (visited_set.size() == N * N) return;
        s = new Square(x, y);
        Square::join(last, s);
        visited_set.insert(y * N + x);
        last = s;
        grid[y][x].emplace_back(s);
    }
}

void bfs(int x, int y) {
    int gx = 0, gy = 0;
    vvi dist(N, vi(N, 1e9));
    vi prev(N * N, -1);
    dist[y][x] = 0;
    queue<int> q;
    q.push(y * N + x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        x = cur % N, y = cur / N;
        if (x == gx && y == gy) break;
        rep(i, 4) {
            char dir = DIRS[i];
            if (!can_move(x, y, dir)) continue;
            int dx = dx4[i], dy = dy4[i];
            int nx = x + dx, ny = y + dy;
            if (dist[ny][nx] != 1e9) continue;
            dist[ny][nx] = dist[y][x] + 1;
            prev[ny * N + nx] = cur;
            q.push(ny * N + nx);
        }
    }
    int cur = gy * N + gx;
    vector<Square *> p;
    while (cur != -1) {
        int x = cur % N, y = cur / N;
        auto s = new Square(x, y);
        p.emplace_back(s);
        cur = prev[cur];
    }
    reverse(all(p));
    for (auto s : p) {
        Square::join(last, s);
        last = s;
    }
}

mt19937 mt(616);

int random_int(int min, int max) { return min + (int)(mt() * (max - min + 1.0) / (1.0 + mt.max())); }

template <typename T>
T random_choice(vector<T> &v) {
    int idx = random_int(0, v.size() - 1);
    return v[idx];
}

int main() {
    Time time;
    cin >> N;
    h.resize(N - 1);
    v.resize(N);
    d.resize(N, vi(N));
    cin >> h >> v >> d;
    rep(i, N) d_sum += accumulate(all(d[i]), 0);

    // とりあえず全頂点を訪れてスコアが最小のものを採用する
    vector<Square *> min_path;
    ll min_score = 1e18;
    visited.assign(N_MAX, vb(N_MAX, false));
    visited_set.clear();
    visited_set.insert(0);
    auto begin = new Square(0, 0);
    last = begin;
    grid[0][0].emplace_back(begin);
    dfs(last);
    bfs(last->x, last->y);
    min_score = calc_score(begin);

    while (!time.is_over(250)) {
        int x = random_int(0, N - 1), y = random_int(0, N - 1);
        auto s = random_choice(grid[y][x]);
        while (s->next == nullptr || s->next->next == nullptr || s->next->next->next == nullptr) {
            x = random_int(0, N - 1), y = random_int(0, N - 1);
            s = random_choice(grid[y][x]);
        }
        auto next1 = s->next;
        auto next2 = next1->next;
        auto next3 = next2->next;
        int dx = next3->x - s->x, dy = next3->y - s->y;
        if (abs(dx) + abs(dy) != 1) continue;
        int w = dir(dx, dy);
        if (!can_move(s->x, s->y, DIRS[w])) continue;
        if (grid[next1->y][next1->x].size() <= 1 || grid[next2->y][next2->x].size() <= 1) continue;
        Square::join(s, next3);
        if (chmin(min_score, calc_score(begin))) {
            grid[next1->y][next1->x].erase(find(all(grid[next1->y][next1->x]), next1));
            grid[next2->y][next2->x].erase(find(all(grid[next2->y][next2->x]), next2));
        } else {
            Square::join(s, next1);
            Square::join(next2, next3);
        }
        cerr << min_score << endl;
    }

    stack<Square *> st;
    while (!time.is_over(1700)) {
        Square *s = nullptr;
        if (st.empty()) {
            int x = random_int(0, N - 1), y = random_int(0, N - 1);
            s = random_choice(grid[y][x]);
            while (s->next == nullptr) {
                x = random_int(0, N - 1), y = random_int(0, N - 1);
                s = random_choice(grid[y][x]);
            }
        } else {
            s = st.top();
            st.pop();
        }
        auto cur_next = s->next;
        int x = s->x, y = s->y;
        int dx = cur_next->x - x, dy = cur_next->y - y;
        int w = dir(dx, dy);
        for (int nw : {(w + 1) % 4, (w - 1 + 4) % 4}) {
            char dir = DIRS[nw];
            if (!can_move(x, y, dir)) continue;  // 移動できない
            auto next1 = s->move(dir);
            if (!can_move(next1->x, next1->y, DIRS[w])) continue;  // 移動できない
            auto next2 = next1->move(DIRS[w]);
            if (!can_move(next2->x, next2->y, DIRS[(nw + 2) % 4])) continue;  // 移動できない
            auto next3 = next2->move(DIRS[(nw + 2) % 4]);
            if (!can_move(next3->x, next3->y, DIRS[nw])) continue;  // 移動できない
            // 戻ってこなければ不採用
            if (next3->x != s->next->x || next3->y != s->next->y) continue;
            Square::join(s, next1);
            Square::join(next1, next2);
            Square::join(next2, cur_next);
            if (chmin(min_score, calc_score(begin))) {
                st.push(s);
                st.push(next1);
                st.push(next2);
                grid[next1->y][next1->x].emplace_back(next1);
                grid[next2->y][next2->x].emplace_back(next2);
            } else {
                Square::join(s, cur_next);
            }
            cerr << min_score << endl;
        }
    }

    while (!time.is_over(1900)) {
        int x = random_int(0, N - 1), y = random_int(0, N - 1);
        auto s = random_choice(grid[y][x]);
        while (s->next == nullptr || s->next->next == nullptr || s->next->next->next == nullptr) {
            x = random_int(0, N - 1), y = random_int(0, N - 1);
            s = random_choice(grid[y][x]);
        }
        auto next1 = s->next;
        auto next2 = next1->next;
        auto next3 = next2->next;
        int dx = next3->x - s->x, dy = next3->y - s->y;
        if (abs(dx) + abs(dy) != 1) continue;
        int w = dir(dx, dy);
        if (!can_move(s->x, s->y, DIRS[w])) continue;
        if (grid[next1->y][next1->x].size() <= 1 || grid[next2->y][next2->x].size() <= 1) continue;
        Square::join(s, next3);
        if (chmin(min_score, calc_score(begin))) {
            grid[next1->y][next1->x].erase(find(all(grid[next1->y][next1->x]), next1));
            grid[next2->y][next2->x].erase(find(all(grid[next2->y][next2->x]), next2));
        } else {
            Square::join(s, next1);
            Square::join(next2, next3);
        }
        cerr << min_score << endl;
    }

    cerr << min_score << endl;
    cout << path_to_ans(begin) << endl;
}
