#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr double eps = 1e-9;
struct point {
    double x, y;
};
point operator+(point a, point b) { return {a.x + b.x, a.y + b.y}; }
point operator-(point a, point b) { return {a.x - b.x, a.y - b.y}; }
point operator*(double t, point b) { return {t * b.x, t * b.y}; }
point operator/(point a, double t) { return {a.x / t, a.y / t}; }
double operator*(point a, point b) { return a.x * b.x + a.y * b.y; }  // dot product
double operator%(point a, point b) { return a.x * b.y - a.y * b.x; }  // cross product
bool operator<(point a, point b) {                                    // lexicographical compare
    if (abs(a.x - b.x) > eps) return a.x < b.x;
    return a.y + eps < b.y;
}
double dot(const point &a, const point &b) { return (a.x * b.x + a.y * b.y); }
double norm(const point &a) { return (a.x * a.x + a.y * a.y); }
double cross(const point &a, const point &b) { return (a.x * b.y - a.y * b.x); }
int ccw(const point &a, point b, point c) {
    b = b - a, c = c - a;
    // 点a, b, c が
    // 反時計回りの時、
    if (cross(b, c) > eps) {
        return 1;
    }
    // 時計回りの時、
    if (cross(b, c) < -eps) {
        return -1;
    }
    // c, a, bがこの順番で同一直線上にある時、
    if (dot(b, c) < 0) {
        return 2;
    }
    // a, b, cがこの順番で同一直線上にある場合、
    if (norm(b) < norm(c)) {
        return -2;
    }
    // cが線分ab上にある場合、
    return 0;
}
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

int N;
point pos(double i) { return {cos(2 * M_PI * i / (2 * N)), sin(2 * M_PI * i / (2 * N))}; }

int main() {
    Time time;
    cin >> N;
    vi A(N), B(N);
    vector<pair<point, point>> v;
    rep(i, N) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
        v.emplace_back(pos(A[i]), pos(B[i]));
    }
    sort(all(v));
    rep(i, N) {
        point a = v[i].first, b = v[i].second;
        point c = v[(i + 1) % N].first, d = v[(i + 1) % N].second;
        if (ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    while (!time.is_over(1900)) {
        int i = rnd.random_int(0, N - 1), j = rnd.random_int(0, N - 1);
        if (i == j) continue;
        auto [a, b] = v[i];
        auto [c, d] = v[j];
        if (ccw(a, b, c) * ccw(a, b, d) < 0 && ccw(c, d, a) * ccw(c, d, b) < 0) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
