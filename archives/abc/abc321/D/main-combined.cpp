#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<long long, long long>>;
template <typename T>
using greater_heap = priority_queue<T, vector<T>, greater<T>>; // ヒープ（小さい順）

#define ov3(a, b, c, name, ...) name
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define rep1(i, n) rep2(i, 0, n)
#define rep0(n) rep1(iiiii, n)
#define rep(...) ov3(__VA_ARGS__, rep2, rep1, rep0)(__VA_ARGS__)
#define foreach(v, c) for (auto &v : c)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define debug(x) cerr << #x << ": " << x << '\n'

int dx4[4] = {0, 1, 0, -1};               // 4方向移動用
int dy4[4] = {1, 0, -1, 0};               // 4方向移動用
int dx8[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // 8方向移動用
int dy8[8] = {1, 1, 0, -1, -1, -1, 0, 1}; // 8方向移動用

// struct in
// {
//     in(){};
//     template <class T>
//     operator T()
//     {
//         T t;
//         cin >> t;
//         return t;
//     }
// };

// @brief 大きい方で更新
// @param a 更新される値
// @param b 更新する値
template <typename T>
inline bool chmax(T &a, const T &b)
{
    return a < b ? a = b, true : false;
}

// @brief 小さい方で更新
// @param a 更新される値
// @param b 更新する値
template <typename T>
inline bool chmin(T &a, const T &b)
{
    return a > b ? a = b, true : false;
}

// @brief グラフの頂点
// @param id 頂点のid
// @param out_neighbors 出次数の頂点
// @param in_neighbors 入次数の頂点
class Vertex
{
public:
    int id;
    vector<Vertex> out_neighbors, in_neighbors;

    Vertex(int id) : id(id) {}

    bool operator==(const Vertex &v) const
    {
        return id == v.id;
    }

    bool operator<(const Vertex &v) const
    {
        return id < v.id;
    }

    bool operator>(const Vertex &v) const
    {
        return id > v.id;
    }

    friend ostream &operator<<(ostream &os, const Vertex &v)
    {
        os << v.id;
        return os;
    }

    operator int() const
    {
        return id;
    }
};

// @brief グラフの枝
//
class Edge
{
public:
    Vertex from, to;
    ll weight;

    Edge(Vertex &from, Vertex &to, ll weight = 1) : from(from), to(to), weight(weight) {}

    friend ostream &operator<<(ostream &os, const Edge &e)
    {
        os << min(e.from, e.to) << ' ' << max(e.from, e.to);
        return os;
    }

    operator pair<Vertex, Vertex>() const
    {
        return {from, to};
    }

    operator pair<int, int>() const
    {
        return {from.id, to.id};
    }
};

/* グラフ */
class Graph
{
private:
    vector<Vertex> __vertexes;
    vector<vector<Edge>> __edges;

public:
    int n;

    // @brief コンストラクタ
    // @param n 頂点数
    Graph(int n) : n(n)
    {
        rep(i, n) __vertexes.push_back(Vertex(i));
        __edges.resize(n);
    }

    // @brief 枝の追加
    // @param e 枝
    // @param directed 有向グラフの場合はtrue
    void add_edge(Edge e, bool directed = false)
    {
        __edges[e.from.id].push_back(e);
        __vertexes[e.from.id].out_neighbors.push_back(e.to);
        __vertexes[e.to.id].in_neighbors.push_back(e.from);
        if (!directed)
        {
            __edges[e.to.id].push_back(Edge(e.to, e.from, e.weight));
            __vertexes[e.to.id].out_neighbors.push_back(e.from);
            __vertexes[e.from.id].in_neighbors.push_back(e.to);
        }
    }

    // @brief 枝の追加
    // @param u, v 枝の端点
    // @param directed 有向グラフの場合はtrue
    void add_edge(int u, int v, bool directed = false)
    {
        add_edge(Edge(__vertexes[u], __vertexes[v]), directed);
    }

    // @brief 枝の追加
    // @param u, v 枝の端点
    // @param weight 枝の重み
    // @param directed 有向グラフの場合はtrue
    void add_edge(int u, int v, ll weight = 1, bool directed = false)
    {
        add_edge(Edge(__vertexes[u], __vertexes[v], weight), directed);
    }

    // @brief ワーシャルフロイド法
    vvl floyd_warshall()
    {
        vvl dist(n, vl(n, 1e18));
        rep(i, n) dist[i][i] = 0;
        rep(i, n)
        {
            for (auto e : __edges[i])
                dist[e.from.id][e.to.id] = e.weight;
        }
        rep(k, n) rep(i, n) rep(j, n)
        {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
        return dist;
    }

    // @brief ダイクストラ法
    // @return 始点から各頂点への最短距離（パスが存在しなければ`1e18`）
    // @param s 始点
    vl dijkstra(int s)
    {
        vl dist(n, 1e18);
        dist[s] = 0;
        greater_heap<pair<ll, Vertex>> pq;
        pq.push({0, __vertexes[s]});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (dist[u.id] < d)
                continue;
            for (auto e : __edges[u.id])
            {
                if (dist[e.to.id] > dist[u.id] + e.weight)
                {
                    dist[e.to.id] = dist[u.id] + e.weight;
                    pq.push({dist[e.to.id], e.to});
                }
            }
        }
        return dist;
    }

    // @brief トポロジカルソート
    // @return トポロジカルソートされた頂点のリスト（DAGでなければ空リスト）
    vi topological_sort()
    {
        vi sorted;
        vi in_degree(n, 0);
        rep(u, n) in_degree[u] = __vertexes[u].in_neighbors.size();
        queue<int> q;
        rep(u, n) if (in_degree[u] == 0) q.push(u);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            sorted.push_back(u);
            for (auto v : __vertexes[u].out_neighbors)
            {
                in_degree[v.id]--;
                if (in_degree[v.id] == 0)
                {
                    q.push(v.id);
                }
            }
        }
        if (sorted.size() != n)
        {
            sorted.clear();
        }
        return sorted;
    }

    // @brief 二部グラフ判定
    // @return 二部グラフならtrue
    bool is_bipartite()
    {
        vi color(n, -1);
        rep(u, n)
        {
            if (color[u] != -1)
                continue;
            color[u] = 0;
            queue<int> q;
            q.push(u);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : __vertexes[u].out_neighbors)
                {
                    if (color[v.id] == -1)
                    {
                        color[v.id] = color[u] ^ 1;
                        q.push(v.id);
                    }
                    else if (color[v.id] == color[u])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    // @brief uに隣接する頂点の集合を返す
    // @param u 頂点
    vector<Edge> &operator[](int u)
    {
        return __edges[u];
    }

    vector<Edge> &operator[](Vertex u)
    {
        return __edges[u.id];
    }
};

// 可変長引数のmin関数
template <class... T>
constexpr auto min(T... a)
{
    return min(initializer_list<common_type_t<T...>>{a...});
}

// vectorを引数に取るmin関数
template <class T>
constexpr auto min(vector<T> a)
{
    return *min_element(a.begin(), a.end());
}

// setを引数に取るmin関数
template <class T>
constexpr auto min(set<T> a)
{
    return *min_element(a.begin(), a.end());
}

// 可変長引数のmax関数
template <class... T>
constexpr auto max(T... a)
{
    return max(initializer_list<common_type_t<T...>>{a...});
}

// vectorを引数に取るmax関数
template <class T>
constexpr auto max(vector<T> a)
{
    return *max_element(a.begin(), a.end());
}

// setを引数に取るmax関数
template <class T>
constexpr auto max(set<T> a)
{
    return *max_element(a.begin(), a.end());
}

/* 素数判定 */
bool is_prime(ll n)
{
    if (n <= 1)
        return false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

/*
@brief 素数を列挙する関数
@param upper 素数の上限
 */
vector<ll> create_primes(ll upper)
{
    vector<ll> primes;
    vector<bool> is_p(upper + 1, true);

    for (ll i = 2; i <= upper; i++)
    {
        if (is_p[i])
        {
            primes.push_back(i);
            for (ll j = i * 2; j <= upper; j += i)
            {
                is_p[j] = false;
            }
        }
    }
    return primes;
}

/* @brief 素因数分解 */
template <class T>
vl prime_factorize(T n)
{
    vl res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res.emplace_back(i);
            n /= i;
        }
    }
    if (n != 1)
    {
        res.emplace_back(n);
    }
    return res;
}

template <class T>
class UnionFind
{
    vector<T> par, rank, siz;

public:
    // @param n 要素数
    UnionFind(T n)
    {
        par = vector<T>(n, -1);
        rank = vector<T>(n, 0);
        siz = vector<T>(n, 1);
    }

    // xの根を求める
    T root(T x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    // xとyが同じグループに属するかどうか（根が一致するかどうか）
    bool same(T x, T y)
    {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループとを併合する
    void unite(T x, T y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return;

        if (rank[x] < rank[y])
            swap(x, y);
        par[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        siz[x] += siz[y];
    }

    // xを含むグループのサイズ
    T size(T x)
    {
        return siz[root(x)];
    }

    // グループ数
    T groups()
    {
        T res = 0;
        for (T i = 0; i < par.size(); i++)
        {
            if (par[i] == -1)
                res++;
        }
        return res;
    }
};

/*
自動的にmodを取ってくれる型
使い方：static_modint<mod> a;
ただし、modは素数でなければならない
*/
template <int mod>
class static_modint
{
    ll x;

public:
    static_modint(ll x = 0) : x((x % mod + mod) % mod) {}
    static_modint operator-() const
    {
        return static_modint(-x);
    }
    static_modint &operator+=(const static_modint &a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    static_modint &operator-=(const static_modint &a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    static_modint &operator*=(const static_modint &a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    static_modint operator+(const static_modint &a) const
    {
        static_modint res(*this);
        return res += a;
    }
    static_modint operator-(const static_modint &a) const
    {
        static_modint res(*this);
        return res -= a;
    }
    static_modint operator*(const static_modint &a) const
    {
        static_modint res(*this);
        return res *= a;
    }
    // 二分累乗法によるべき乗
    static_modint pow(ll t) const
    {
        if (!t)
            return 1;
        static_modint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }
    // 逆元を求める
    static_modint inv() const
    {
        return pow(mod - 2);
    }
    static_modint &operator/=(const static_modint &a)
    {
        return (*this) *= a.inv();
    }
    static_modint operator/(const static_modint &a) const
    {
        static_modint res(*this);
        return res /= a;
    }

    friend ostream &operator<<(ostream &os, const static_modint &m)
    {
        os << m.x;
        return os;
    }
};

// 桁和
template <class T>
int digit_sum(T n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << " ";
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, const vector<vector<T>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        os << v[i];
        if (i != v.size() - 1)
            os << endl;
    }
    return os;
}

template <typename T>
void print(T v)
{
    cout << v << endl;
}
#line 2 "abc321/D/main.cpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M, P;
    cin >> N >> M >> P;
    vl A(N), B(M), B_diff(M), B_sum(M + 1, 0), B_sum_diff(M + 1, 0);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(all(B));
    rep(i, M) B_diff[i] = B[i] - P;
    rep(i, M + 1)
    {
        if (i == 0)
            continue;
        B_sum[i] = B_sum[i - 1] + B[i - 1];
    }
    ll ans = 0;
    rep(i, N)
    {
        ll a = A[i];
        ll idx = lower_bound(all(B), P - a) - B.begin();
        ans += B_sum[idx];
        ans += a * idx;
        ans += P * (M - idx);
    }
    cout << ans << endl;
}
