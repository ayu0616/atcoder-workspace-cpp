#include <bits/stdc++.h>

using namespace std;

// 型エイリアス
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vs = vector<string>;
using vb = vector<bool>;
using vvb = vector<vb>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;

// マクロ
#define ov3(a, b, c, name, ...) name
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define rep1(i, n) rep2(i, 0, n)
#define rep0(n) rep1(iiiii, n)
#define rep(...) ov3(__VA_ARGS__, rep2, rep1, rep0)(__VA_ARGS__)
#define foreach(v, c) for (auto &v : c)
#define all(x) (x).begin(), (x).end()
#define ALL(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define RALL(x) (x).rbegin(), (x).rend()
#define debug(x) cerr << #x << ": " << x << '\n'

// 移動
constexpr int dx4[4] = {1, 0, -1, 0};  // 4方向移動用
constexpr int dy4[4] = {0, 1, 0, -1};  // 4方向移動用
const map<char, int> RULD_map = {{'R', 0}, {'U', 1}, {'L', 2}, {'D', 3}};

constexpr int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};  // 8方向移動用
constexpr int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};  // 8方向移動用

// 最大値
constexpr int INT_INF = 1 << 30;  // intの最大値
constexpr ll LL_INF = 1LL << 60;  // llの最大値

// @brief Yes/Noを出力する
// @param b 条件
// @param yes 出力する文字列（デフォルトは`Yes`）
// @param no 出力する文字列（デフォルトは`No`）
inline bool yes_no(bool b, string yes = "Yes", string no = "No") {
    cout << (b ? yes : no) << endl;
    return b;
}

// @brief ヒープ（小さい順）
template <typename T>
class greater_heap {
   private:
    priority_queue<T, vector<T>, greater<T>> q;

   public:
    greater_heap() : q() {}

    bool empty() { return q.empty(); }
    bool not_empty() { return !q.empty(); }

    void print_all() {
        while (not_empty()) {
            cout << q.top() << endl;
            q.pop();
        }
    }

    void push(T x) { return q.push(x); }

    void pop() { return q.pop(); }

    T top() const { return q.top(); }
};

// @brief 大きい方で更新
// @param a 更新される値
// @param b 更新する値
template <typename T>
inline bool chmax(T &a, const T &b) {
    return a < b ? a = b, true : false;
}

// @brief 小さい方で更新
// @param a 更新される値
// @param b 更新する値
template <typename T>
inline bool chmin(T &a, const T &b) {
    return a > b ? a = b, true : false;
}

// 可変長引数のmin関数
template <class... T>
constexpr auto min(T... a) {
    return min(initializer_list<common_type_t<T...>>{a...});
}

// vectorを引数に取るmin関数
template <class T>
constexpr auto min(vector<T> a) {
    return *min_element(a.begin(), a.end());
}

// setを引数に取るmin関数
template <class T>
constexpr auto min(set<T> a) {
    return *min_element(a.begin(), a.end());
}

// 可変長引数のmax関数
template <class... T>
constexpr auto max(T... a) {
    return max(initializer_list<common_type_t<T...>>{a...});
}

// vectorを引数に取るmax関数
template <class T>
constexpr auto max(vector<T> a) {
    return *max_element(a.begin(), a.end());
}

// setを引数に取るmax関数
template <class T>
constexpr auto max(set<T> a) {
    return *max_element(a.begin(), a.end());
}


struct Edge;

// @brief グラフの頂点
struct Vertex {
    int id;
    vector<Edge> edges;

    Vertex(int id) {
        this->id = id;
        this->edges = vector<Edge>();
    }

    operator int() const { return this->id; }
};

// @brief グラフの辺
// @param to 辺の行き先
// @param cost 辺のコスト
struct Edge {
    Vertex *from, *to;
    ll cost;

    Edge(int from, int to, ll cost = 1) {
        this->from = new Vertex(from);
        this->to = new Vertex(to);
        this->cost = cost;
    }

    Edge(Vertex *from, Vertex *to, ll cost = 1) {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }

    operator int() const { return this->to->id; }
};

// @brief グラフ
class Graph : vector<Vertex> {
    int n;

   public:
    Graph() : vector<Vertex>() { this->n = 0; }
    Graph(int n) {
        this->n = n;
        rep(i, n) this->push_back(Vertex(i));
    }

    inline void resize(int n) {
        this->n = n;
        rep(i, n) this->push_back(Vertex(i));
    }

    inline void add_edge(int from, int to, ll cost = 1) {
        Vertex &u = this->at(from);
        Vertex &v = this->at(to);
        Edge e(u, v, cost);
        u.edges.push_back(e);
    }

    // @brief ダイクストラ法
    // @param start 始点
    // @return 始点からの最短距離（到達不可能な点への距離は-1とする）
    vl dyjkstra(int start) const {
        vl dist(n, LL_INF);
        dist[start] = 0;
        priority_queue<pll, vpll, greater<pll>> que;
        que.push({0, start});
        while (!que.empty()) {
            pll p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (auto e : this->at(v).edges) {
                if (dist[*e.to] > dist[v] + e.cost) {
                    dist[*e.to] = dist[v] + e.cost;
                    que.push({dist[*e.to], *e.to});
                }
            }
        }
        rep(i, n) if (dist[i] == LL_INF) dist[i] = -1;
        return dist;
    }

    // @brief ワーシャルフロイド法
    // @return 全点間の最短距離（到達不可能な点への距離は-1とする）
    vvl warshall_floyd() const {
        vvl dist(n, vl(n, LL_INF));
        rep(i, n) dist[i][i] = 0;
        rep(i, n) {
            for (auto e : this->at(i).edges) {
                dist[i][*e.to] = e.cost;
            }
        }
        rep(k, n) {
            rep(i, n) {
                rep(j, n) {
                    if (dist[i][k] != LL_INF && dist[k][j] != LL_INF) {
                        chmin(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        rep(i, n) rep(j, n) if (dist[i][j] == LL_INF) dist[i][j] = -1;
        return dist;
    }

    // @brief ベルマンフォード法
    // @param start 始点
    // @return 始点からの最短距離（到達不可能な点への距離は-1とする）
    vl bellman_ford(int start) const {
        vl dist(n, LL_INF);
        dist[start] = 0;
        rep(i, n) {
            rep(j, n) {
                for (auto e : this->at(j).edges) {
                    if (dist[j] != LL_INF && dist[*e.to] > dist[j] + e.cost) {
                        dist[*e.to] = dist[j] + e.cost;
                        if (i == n - 1) dist[*e.to] = LLONG_MIN;
                    }
                }
            }
        }
        rep(i, n) if (dist[i] == LL_INF) dist[i] = -1;
        return dist;
    }

    // @brief トポロジカルソート
    // @return トポロジカルソートされた頂点のリスト
    vi topological_sort() const {
        vi res;
        vb used(n, false);
        function<void(int)> dfs = [&](int v) {
            used[v] = true;
            for (auto e : this->at(v).edges) {
                if (!used[*e.to]) dfs(*e.to);
            }
            res.push_back(v);
        };
        rep(i, n) {
            if (!used[i]) dfs(i);
        }
        reverse(all(res));
        return res;
    }

    // TODO: UnionFindを使えるようにする
    // @brief 強連結成分分解
    // @param rev このグラフと逆向きの辺を持つグラフ
    // UnionFind<int> scc(Graph rev) const {
    //     vi num;
    //     vb visited(n, false);

    //     function<void(int)> dfs;
    //     dfs = [&](int v) {
    //         visited[v] = true;
    //         for (auto u : this->at(v).edges) {
    //             if (visited[u]) continue;
    //             dfs(u);
    //         }
    //         num.push_back(v);
    //     };
    //     rep(i, n) {
    //         if (!visited[i]) dfs(i);
    //     }
    //     reverse(all(num));

    //     rep(i, n) visited[i] = false;
    //     UnionFind uf(n);
    //     function<void(int)> dfs2;
    //     dfs2 = [&](int v) {
    //         visited[v] = true;
    //         for (auto u : rev[v]) {
    //             if (visited[u]) continue;
    //             uf.unite(v, u);
    //             dfs2(u);
    //         }
    //     };
    //     for (auto v : num) {
    //         if (!visited[v]) dfs2(v);
    //     }
    //     return uf;
    // }

    vector<Edge> operator[](int id) const { return this->at(id).edges; }
};

struct SegTree {
   private:
    int n;
    vl dat, lazy;

   public:
    SegTree(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        dat.resize(2 * n - 1, LL_INF);
        lazy.resize(2 * n - 1, LL_INF);
    }

    void eval(int k) {
        if (lazy[k] == LL_INF) return;
        if (k < n - 1) {
            lazy[k * 2 + 1] = lazy[k];
            lazy[k * 2 + 2] = lazy[k];
        }
        dat[k] = lazy[k];
        lazy[k] = LL_INF;
    }

    void update(int a, int b, ll x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {
            lazy[k] = x;
            eval(k);
        } else if (a < r && l < b) {
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);
            dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, ll x) { update(a, b, x, 0, 0, n); }

    ll query(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) return LL_INF;
        if (a <= l && r <= b) return dat[k];

        ll vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(vl, vr);
    }

    // @brief [a, b)の最小値を求める
    ll query(int a, int b) { return query(a, b, 0, 0, n); }

    ll operator[](int a) { return query(a, a + 1); }
};

/*
自動的にmodを取ってくれる型
使い方：static_modint<mod> a;
ただし、modは素数でなければならない
*/
template <int mod>
class static_modint {
    ll x;

   public:
    inline static_modint(ll x = 0) : x((x % mod + mod) % mod) {}
    inline static_modint operator-() const { return static_modint(-x); }
    inline static_modint &operator+=(const static_modint &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    inline static_modint &operator-=(const static_modint &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    inline static_modint &operator*=(const static_modint &a) {
        (x *= a.x) %= mod;
        return *this;
    }
    inline static_modint operator+(const static_modint &a) const {
        static_modint res(*this);
        return res += a;
    }
    inline static_modint operator-(const static_modint &a) const {
        static_modint res(*this);
        return res -= a;
    }
    inline static_modint operator*(const static_modint &a) const {
        static_modint res(*this);
        return res *= a;
    }
    // 二分累乗法によるべき乗
    inline static_modint pow(ll t) const {
        if (!t) return 1;
        static_modint a = pow(t >> 1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }
    inline static_modint pow(const static_modint &t) const { return pow(t.x); }
    // 逆元を求める
    inline static_modint inv() const { return pow(mod - 2); }
    inline static_modint &operator/=(const static_modint &a) { return (*this) *= a.inv(); }
    inline static_modint operator/(const static_modint &a) const {
        static_modint res(*this);
        return res /= a;
    }

    inline int val() const { return x; }

    friend ostream &operator<<(ostream &os, const static_modint &m) {
        os << m.x;
        return os;
    }

    friend bool operator==(const static_modint &lhs, const static_modint &rhs) { return lhs.x == rhs.x; }
};

// 桁和
template <class T>
constexpr int digit_sum(T n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

template <class T>
inline istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v) is >> i;
    return is;
}

template <class T>
inline ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) os << " ";
    }
    return os;
}

template <class T>
inline ostream &operator<<(ostream &os, const vector<vector<T>> &v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i != v.size() - 1) os << endl;
    }
    return os;
}

template <class T>
inline ostream &operator<<(ostream &os, set<T> &s) {
    ll i = 0;
    for (T v : s) {
        cout << v;
        if (i++ < s.size() - 1) os << " ";
    }
    return os;
}

template <class T>
inline ostream &operator<<(ostream &os, priority_queue<T> q) {
    ll i = 0;
    while (!q.empty()) {
        cout << q.top();
        q.pop();
        if (i++ < q.size() - 1) os << " ";
    }
    return os;
}
template <class T>
inline ostream &operator<<(ostream &os, greater_heap<T> q) {
    ll i = 0;
    while (!q.empty()) {
        cout << q.top();
        q.pop();
        if (i++ < q.size() - 1) os << " ";
    }
    return os;
}

template <class T, class S>
inline ostream &operator<<(ostream &os, pair<T, S> p) {
    os << p.first << " " << p.second;
    return os;
}

template <typename T>
inline void print(T v) {
    cout << v << endl;
}

void dfs_combination(int n, int r, int from, vi &use, vvi &uses) {
    if (from + r > n) {
        return;
    } else if (r == 0) {
        uses.push_back(use);
        return;
    }
    use.push_back(from);
    dfs_combination(n, r - 1, from + 1, use, uses);
    use.pop_back();
    dfs_combination(n, r, from + 1, use, uses);
}

// @brief 組み合わせを全列挙する
template <class T>
vector<vector<T>> combinations(vector<T> &v, int r) {
    int n = v.size();
    vi use;
    vvi uses;
    dfs_combination(n, r, 0, use, uses);
    vector<vector<T>> res(uses.size());
    rep(i, uses.size()) {
        vi &u = uses[i];
        vector<T> tmp;
        for (auto &i : u) {
            tmp.push_back(v[i]);
        }
        res[i] = tmp;
    }
    return res;
}

template <typename T = ll>
struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator*(const T &d) const { return Point(x * d, y * d); }
    Point operator/(const T &d) const { return Point(x / d, y / d); }
    T dot(const Point &p) const { return x * p.x + y * p.y; }
    T cross(const Point &p) const { return x * p.y - y * p.x; }
    T norm() const { return x * x + y * y; }
    double abs() const { return sqrt(norm()); }
    bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
    bool operator==(const Point &p) const { return x == p.x && y == p.y; }
};