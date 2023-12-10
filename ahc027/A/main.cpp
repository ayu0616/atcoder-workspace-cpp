#include "../../lib.hpp"

int N, d_sum = 0;
constexpr int L_MAX = 1e5, N_MAX = 40;
constexpr char DIRS[] = "RDLU";
map<char, int> DIR_IDX = {{'R', 0}, {'D', 1}, {'L', 2}, {'U', 3}};
vs h, v;
vvi d;       // 汚れやすさ
vi d_accum;  // dの累積和

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

    pii random_weighted() {
        int r = random_int(0, d_sum);
        int idx = upper_bound(all(d_accum), r) - d_accum.begin() - 1;
        return {idx % N, idx / N};
    }

    template <typename T>
    T random_choice(vector<T> &v) {
        int idx = random_int(0, v.size() - 1);
        return v[idx];
    }
};

// 移動方向を表す構造体
struct Dir {
    int dx, dy;  // 移動量
    char c;      // 移動方向の記号
    int idx;     // DIRSのインデックス

    Dir(int dx, int dy) {
        this->dx = dx;
        this->dy = dy;
        if (dx == 1 && dy == 0)
            this->idx = 0;
        else if (dx == 0 && dy == 1)
            this->idx = 1;
        else if (dx == -1 && dy == 0)
            this->idx = 2;
        else if (dx == 0 && dy == -1)
            this->idx = 3;
        else
            assert(false);
        this->c = DIRS[idx];
    }

    Dir(char c) {
        this->c = c;
        this->idx = DIR_IDX[c];
        this->dx = dx4[idx];
        this->dy = dy4[idx];
    }

    Dir(int idx) {
        this->idx = idx;
        this->c = DIRS[idx];
        this->dx = dx4[idx];
        this->dy = dy4[idx];
    }

    Dir reverse() { return Dir((idx + 2) % 4); }

    Dir operator-() { return reverse(); }

    Dir operator+(Dir &d) { return Dir((idx + d.idx) % 4); }
    Dir operator+(int i) { return Dir((idx + i) % 4); }
};

// (x, y)から(nx, ny)に移動できるかどうか
bool can_move(int x, int y, int nx, int ny) {
    if (abs(x - nx) + abs(y - ny) != 1) return false;
    if (nx < 0 || N <= nx || ny < 0 || N <= ny) return false;
    if (x == nx) {
        if (y < ny)
            return h[y][x] == '0';
        else
            return h[ny][x] == '0';
    } else {
        if (x < nx)
            return v[y][x] == '0';
        else
            return v[y][nx] == '0';
    }
}

struct State {
    ll score;
    vector<pii> path;
    vvi grid_cnt;  // 各マスに何回通ったか

    State() : score(0) {}

    void calc_score() {
        int L = path.size();
        vvi last_visited(N, vi(N, -1));

        // 1週目
        rep(i, 1, path.size()) {
            int x = path[i].first, y = path[i].second;
            last_visited[y][x] = i;
        }
        ll cur_score = 0;
        vvi cur_d(N, vi(N));
        rep(i, N) rep(j, N) cur_score += (cur_d[i][j] = d[i][j] * (L - 1 - last_visited[i][j]));
        ll total_score = 0;
        last_visited.assign(N, vi(N, 0));

        // 2周目以降（ここの平均スコアを求めたい）
        rep(i, 1, path.size()) {
            int x = path[i].first, y = path[i].second;
            cur_score += d_sum - d[y][x] * (i - last_visited[y][x]) - cur_d[y][x];
            total_score += cur_score;
            last_visited[y][x] = i;
            cur_d[y][x] = 0;
        }
        score = total_score / (L - 1);
    }

    // 解を出力
    void print() {
        rep(i, path.size() - 1) {
            int x = path[i].first, y = path[i].second;
            int nx = path[i + 1].first, ny = path[i + 1].second;
            int dx = nx - x, dy = ny - y;
            cout << Dir(dx, dy).c;
        }
        cout << endl;
    }

    // BFSで最短経路を移動し現在のpathに追加
    vpii bfs(int sx, int sy, int gx, int gy) {
        constexpr int INF = 1e9;
        vvi dist(N, vi(N, INF));
        vvi prev(N, vi(N, -1));
        queue<pii> que;
        que.emplace(sx, sy);
        dist[sy][sx] = 0;
        while (!que.empty()) {
            int x = que.front().first, y = que.front().second;
            que.pop();
            if (x == gx && y == gy) break;
            rep(i, 4) {
                int nx = x + dx4[i], ny = y + dy4[i];
                if (can_move(x, y, nx, ny) && dist[ny][nx] == INF) {
                    que.emplace(nx, ny);
                    dist[ny][nx] = dist[y][x] + 1;
                    prev[ny][nx] = i;
                }
            }
        }
        int x = gx, y = gy;
        vpii p;
        while (x != sx || y != sy) {
            int idx = prev[y][x];
            p.emplace_back(x, y);
            x -= dx4[idx], y -= dy4[idx];
        }
        reverse(all(p));
        return p;
    }

    // DFSで解を生成
    void dfs(int x, int y) {
        set<pii> visited;
        grid_cnt.assign(N, vi(N, 0));
        visited.emplace(x, y);
        path.emplace_back(x, y);
        grid_cnt[y][x]++;
        _dfs(x, y, visited);
    }

    void _dfs(int x, int y, set<pii> &visited) {
        rep(i, 4) {
            int nx = x + dx4[i], ny = y + dy4[i];
            if (can_move(x, y, nx, ny) && visited.find({nx, ny}) == visited.end()) {
                visited.emplace(nx, ny);
                auto [bx, by] = path.back();
                insert_path(bx, by, nx, ny, path.end());
                _dfs(nx, ny, visited);
                if (visited.size() == N * N) return;
                // insert_path(nx, ny, bx, by, path.end());
            }
        }
    }

    void insert(int idx, int x, int y) {
        path.insert(path.begin() + idx, {x, y});
        grid_cnt[y][x]++;
    }

    void insert_path(int sx, int sy, int gx, int gy, vpii::iterator it) {
        auto p = bfs(sx, sy, gx, gy);
        for (auto [x, y] : p) grid_cnt[y][x]++;
        path.insert(it, all(p));
    }

    void erase(int idx) {
        int x = path[idx].first, y = path[idx].second;
        grid_cnt[y][x]--;
        path.erase(path.begin() + idx);
    }

    void delete_path(int sidx, int gidx) {
        rep(i, sidx, gidx + 1) {
            int x = path[i].first, y = path[i].second;
            grid_cnt[y][x]--;
        }
        path.erase(path.begin() + sidx, path.begin() + gidx + 1);
    }

    bool can_delete(int sidx, int gidx) {
        vvi del_cnt(N, vi(N, 0));
        rep(i, sidx, gidx + 1) {
            int x = path[i].first, y = path[i].second;
            del_cnt[y][x]++;
        }
        rep(i, sidx, gidx + 1) {
            int x = path[i].first, y = path[i].second;
            if (grid_cnt[y][x] - del_cnt[y][x] == 0) return false;
        }
        return true;
    }
};

int main() {
    Time time;  // 時間計測

    // 入力
    cin >> N;
    h.resize(N - 1);
    v.resize(N);
    d.resize(N, vi(N));
    cin >> h >> v >> d;
    rep(i, N) d_sum += accumulate(all(d[i]), 0);
    d_accum.resize(N * N + 1, 0);
    rep(i, N) rep(j, N) d_accum[i * N + j + 1] = d_accum[i * N + j] + d[i][j];

    // 解の生成
    Random rnd;
    State state;
    state.dfs(0, 0);
    auto [x, y] = state.path.back();
    state.insert_path(x, y, 0, 0, state.path.end());
    state.calc_score();

    const double start_temp = N * (d_sum / N / N), end_temp = N * 10;

    auto add = [&](int time_start, int time_limit) {
        int sidx = rnd.random_int(0, state.path.size() - 2);
        auto [x, y] = state.path[sidx];
        auto [nx, ny] = state.path[sidx + 1];
        Dir dir(nx - x, ny - y);
        for (int i : {-1, 1}) {
            Dir w = dir + i;
            vpii p;
            int nx1 = x + w.dx, ny1 = y + w.dy;
            if (!can_move(x, y, nx1, ny1)) return;
            p.emplace_back(nx1, ny1);
            int nx2 = nx1 + dir.dx, ny2 = ny1 + dir.dy;
            auto [bx, by] = p.back();
            if (!can_move(bx, by, nx2, ny2)) return;
            p.emplace_back(nx2, ny2);
            auto tmp = state;
            tmp.erase(sidx + 1);
            rep(i, p.size()) {
                auto [x, y] = p[i];
                tmp.insert(sidx + i + 1, x, y);
            }
            tmp.insert_path(p.back().first, p.back().second, nx, ny, tmp.path.begin() + sidx + p.size() + 1);
            tmp.calc_score();
            double temp = start_temp + (end_temp - start_temp) * (time.get() - time_start) / (time_limit - time_start);
            double prob = exp((state.score - tmp.score) / temp);
            if (rnd() < prob) {
                state = tmp;
                cerr << state.score << endl;
                break;
            }
        }
    };

    auto erase = [&](int time_start, int time_limit) {
        auto tmp = state;
        int sidx = rnd.random_int(0, tmp.path.size() - 2);
        int gidx = rnd.random_int(sidx + 1, min(tmp.path.size() - 1, sidx + 2 * N));
        if (!tmp.can_delete(sidx, gidx)) return;
        auto [sx, sy] = tmp.path[sidx];
        auto [gx, gy] = tmp.path[gidx];
        tmp.delete_path(sidx, gidx);
        tmp.insert(sidx, sx, sy);
        tmp.insert_path(sx, sy, gx, gy, tmp.path.begin() + sidx + 1);
        tmp.calc_score();
        double temp = start_temp + (end_temp - start_temp) * (time.get() - time_start) / (time_limit - time_start);
        double prob = exp((state.score - tmp.score) / temp);
        if (rnd() < prob) {
            state = tmp;
            cerr << state.score << endl;
        }
    };

    int time_start, time_limit;

    // 追加
    time_start = time.get();
    time_limit = 800;
    while (!time.is_over(time_limit)) {
        add(time_start, time_limit);
    }
    // 削除
    time_start = time.get();
    time_limit = 900;
    while (!time.is_over(time_limit)) {
        erase(time_start, time_limit);
    }
    // 追加
    time_start = time.get();
    time_limit = 1800;
    while (!time.is_over(time_limit)) {
        add(time_start, time_limit);
    }
    // 削除
    time_start = time.get();
    time_limit = 1900;
    while (!time.is_over(time_limit)) {
        erase(time_start, time_limit);
    }

    auto tmp = state;
    reverse(all(tmp.path));
    tmp.calc_score();
    if (tmp.score < state.score) state = tmp;

    cerr << state.score << endl;
    state.print();
}
