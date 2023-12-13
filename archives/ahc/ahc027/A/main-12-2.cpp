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
vvi d, cur_d;
string ans = "D", tmp_ans = "";
ll score = 1e18, tmp_score = 0;
vi path;

struct Time {
    chrono::system_clock::time_point start;
    Time() { start = chrono::system_clock::now(); }

    // 経過時間をミリ秒で取得
    ll get() {
        auto end = chrono::system_clock::now();
        return chrono::duration_cast<chrono::milliseconds>(end - start).count();
    }
};

// pathは移動後のマス
ll calc_score(vi path) {
    int L = path.size();
    int x = 0, y = 0;
    // 1週目
    rep(l, L) {
        int idx = path[l];
        x = idx % N, y = idx / N;
        rep(i, N) rep(j, N) cur_d[i][j] += d[i][j];
        cur_d[y][x] = 0;
    }
    // 2週目
    ll score = 0, accum_score = 0;
    rep(i, N) rep(j, N) score += cur_d[i][j];
    rep(l, L) {
        int idx = path[l];
        x = idx % N, y = idx / N;
        rep(i, N) rep(j, N) cur_d[i][j] += d[i][j];
        score += d_sum - cur_d[y][x];
        accum_score += score;
        cur_d[y][x] = 0;
    }
    return accum_score / L;
}

// pathから移動方向文字列を生成する
string path_to_ans(vi path) {
    int L = path.size();
    int cur = 0;
    string ans = "";
    rep(l, L) {
        int next = path[l];
        int diff = next - cur;
        if (diff == 1)
            ans += 'R';
        else if (diff == -1)
            ans += 'L';
        else if (diff == N)
            ans += 'D';
        else if (diff == -N)
            ans += 'U';
        cur = next;
    }
    return ans;
}

// 汚れを更新する
void update_dirty(int x, int y) {
    rep(i, N) rep(j, N) cur_d[i][j] += d[i][j];
    tmp_score += d_sum - cur_d[y][x] - d[y][x];
    cur_d[y][x] = 0;
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

vvb visited(N_MAX, vb(N_MAX, false));
void dfs(int x, int y, int w = 0) {
    visited[y][x] = true;
    rep(i, 4) {
        int j = (i + w) % 4;
        char dir = DIRS[j];
        if (!can_move(x, y, dir)) continue;
        int dx = dx4[j], dy = dy4[j];
        int nx = x + dx, ny = y + dy;
        if (visited[ny][nx]) continue;
        // 行き
        // tmp_ans += DIRS[j];
        // update_dirty(nx, ny);
        path.push_back(ny * N + nx);
        dfs(nx, ny);
        // 帰り
        // tmp_ans += DIRS[(j + 2) % 4];
        // update_dirty(x, y);
        path.push_back(y * N + x);
    }
}

int random_int(int min, int max) { return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX)); }

int main() {
    Time time;
    cin >> N;
    h.resize(N - 1);
    v.resize(N);
    d.resize(N, vi(N));
    cin >> h >> v >> d;
    cur_d = d;
    rep(i, N) d_sum += accumulate(all(d[i]), 0);

    // とりあえず全頂点を訪れてスコアが最小のものを採用する
    vi min_path;
    ll min_score = 1e18;
    rep(i, 4) {
        tmp_score = d_sum;
        tmp_ans = "";
        cur_d.assign(N, vi(N, 0));
        visited.assign(N_MAX, vb(N_MAX, false));
        path.clear();
        dfs(0, 0, i);
        if (chmin(min_score, calc_score(path))) min_path = path;
    }
    path = min_path;

    stack<int> st;
    while (time.get() < 1900) {
        int L = path.size();
        int idx;
        if(st.empty()) {
            idx = random_int(0, L - 1);
        } else {
            idx = st.top();
            st.pop();
        }
        int x = path[idx] % N, y = path[idx] / N;
        rep(w, 4){
        char dir = DIRS[w];
        if (!can_move(x, y, dir)) continue;  // 移動できない
        int dx = dx4[w], dy = dy4[w];
        int nx = x + dx, ny = y + dy;
        if (path[idx + 1] == ny * N + nx) continue;  // 挿入しても意味ない
        path.insert(path.begin() + idx + 1, ny * N + nx);
        path.insert(path.begin() + idx + 2, y * N + x);
        cerr << min_score << endl;
        if (chmin(min_score, calc_score(path))) {
            min_path = path;
            st.push(idx + 1);
        } else {
            path = min_path;
        }}
    }

    cerr << min_score << endl;
    cout << path_to_ans(min_path) << endl;
}
