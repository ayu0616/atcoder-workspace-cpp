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

mt19937 mt(616);

int random_int(int min, int max) { return min + (int)(mt() * (max - min + 1.0) / (1.0 + mt.max())); }
pii random_weighted() {
    int r = random_int(0, d_sum);
    int idx = lower_bound(all(d_accum), r) - d_accum.begin() - 1;
    chmax(idx, 0);
    return {idx % N, idx / N};
}

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
    d_accum.resize(N * N + 1, 0);
    rep(i, N) rep(j, N) d_accum[i * N + j + 1] = d_accum[i * N + j] + d[i][j];
}
