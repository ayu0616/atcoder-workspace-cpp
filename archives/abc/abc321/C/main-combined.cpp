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
#line 2 "abc321/C/main.cpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;


const ll ans[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 21, 30, 31, 32, 40, 41, 42, 43, 50, 51, 52, 53, 54, 60, 61, 62, 63, 64, 65, 70, 71, 72, 73, 74, 75, 76, 80, 81, 82, 83, 84, 85, 86, 87, 90, 91, 92, 93, 94, 95, 96, 97, 98, 210, 310, 320, 321, 410, 420, 421, 430, 431, 432, 510, 520, 521, 530, 531, 532, 540, 541, 542, 543, 610, 620, 621, 630, 631, 632, 640, 641, 642, 643, 650, 651, 652, 653, 654, 710, 720, 721, 730, 731, 732, 740, 741, 742, 743, 750, 751, 752, 753, 754, 760, 761, 762, 763, 764, 765, 810, 820, 821, 830, 831, 832, 840, 841, 842, 843, 850, 851, 852, 853, 854, 860, 861, 862, 863, 864, 865, 870, 871, 872, 873, 874, 875, 876, 910, 920, 921, 930, 931, 932, 940, 941, 942, 943, 950, 951, 952, 953, 954, 960, 961, 962, 963, 964, 965, 970, 971, 972, 973, 974, 975, 976, 980, 981, 982, 983, 984, 985, 986, 987, 3210, 4210, 4310, 4320, 4321, 5210, 5310, 5320, 5321, 5410, 5420, 5421, 5430, 5431, 5432, 6210, 6310, 6320, 6321, 6410, 6420, 6421, 6430, 6431, 6432, 6510, 6520, 6521, 6530, 6531, 6532, 6540, 6541, 6542, 6543, 7210, 7310, 7320, 7321, 7410, 7420, 7421, 7430, 7431, 7432, 7510, 7520, 7521, 7530, 7531, 7532, 7540, 7541, 7542, 7543, 7610, 7620, 7621, 7630, 7631, 7632, 7640, 7641, 7642, 7643, 7650, 7651, 7652, 7653, 7654, 8210, 8310, 8320, 8321, 8410, 8420, 8421, 8430, 8431, 8432, 8510, 8520, 8521, 8530, 8531, 8532, 8540, 8541, 8542, 8543, 8610, 8620, 8621, 8630, 8631, 8632, 8640, 8641, 8642, 8643, 8650, 8651, 8652, 8653, 8654, 8710, 8720, 8721, 8730, 8731, 8732, 8740, 8741, 8742, 8743, 8750, 8751, 8752, 8753, 8754, 8760, 8761, 8762, 8763, 8764, 8765, 9210, 9310, 9320, 9321, 9410, 9420, 9421, 9430, 9431, 9432, 9510, 9520, 9521, 9530, 9531, 9532, 9540, 9541, 9542, 9543, 9610, 9620, 9621, 9630, 9631, 9632, 9640, 9641, 9642, 9643, 9650, 9651, 9652, 9653, 9654, 9710, 9720, 9721, 9730, 9731, 9732, 9740, 9741, 9742, 9743, 9750, 9751, 9752, 9753, 9754, 9760, 9761, 9762, 9763, 9764, 9765, 9810, 9820, 9821, 9830, 9831, 9832, 9840, 9841, 9842, 9843, 9850, 9851, 9852, 9853, 9854, 9860, 9861, 9862, 9863, 9864, 9865, 9870, 9871, 9872, 9873, 9874, 9875, 9876, 43210, 53210, 54210, 54310, 54320, 54321, 63210, 64210, 64310, 64320, 64321, 65210, 65310, 65320, 65321, 65410, 65420, 65421, 65430, 65431, 65432, 73210, 74210, 74310, 74320, 74321, 75210, 75310, 75320, 75321, 75410, 75420, 75421, 75430, 75431, 75432, 76210, 76310, 76320, 76321, 76410, 76420, 76421, 76430, 76431, 76432, 76510, 76520, 76521, 76530, 76531, 76532, 76540, 76541, 76542, 76543, 83210, 84210, 84310, 84320, 84321, 85210, 85310, 85320, 85321, 85410, 85420, 85421, 85430, 85431, 85432, 86210, 86310, 86320, 86321, 86410, 86420, 86421, 86430, 86431, 86432, 86510, 86520, 86521, 86530, 86531, 86532, 86540, 86541, 86542, 86543, 87210, 87310, 87320, 87321, 87410, 87420, 87421, 87430, 87431, 87432, 87510, 87520, 87521, 87530, 87531, 87532, 87540, 87541, 87542, 87543, 87610, 87620, 87621, 87630, 87631, 87632, 87640, 87641, 87642, 87643, 87650, 87651, 87652, 87653, 87654, 93210, 94210, 94310, 94320, 94321, 95210, 95310, 95320, 95321, 95410, 95420, 95421, 95430, 95431, 95432, 96210, 96310, 96320, 96321, 96410, 96420, 96421, 96430, 96431, 96432, 96510, 96520, 96521, 96530, 96531, 96532, 96540, 96541, 96542, 96543, 97210, 97310, 97320, 97321, 97410, 97420, 97421, 97430, 97431, 97432, 97510, 97520, 97521, 97530, 97531, 97532, 97540, 97541, 97542, 97543, 97610, 97620, 97621, 97630, 97631, 97632, 97640, 97641, 97642, 97643, 97650, 97651, 97652, 97653, 97654, 98210, 98310, 98320, 98321, 98410, 98420, 98421, 98430, 98431, 98432, 98510, 98520, 98521, 98530, 98531, 98532, 98540, 98541, 98542, 98543, 98610, 98620, 98621, 98630, 98631, 98632, 98640, 98641, 98642, 98643, 98650, 98651, 98652, 98653, 98654, 98710, 98720, 98721, 98730, 98731, 98732, 98740, 98741, 98742, 98743, 98750, 98751, 98752, 98753, 98754, 98760, 98761, 98762, 98763, 98764, 98765, 543210, 643210, 653210, 654210, 654310, 654320, 654321, 743210, 753210, 754210, 754310, 754320, 754321, 763210, 764210, 764310, 764320, 764321, 765210, 765310, 765320, 765321, 765410, 765420, 765421, 765430, 765431, 765432, 843210, 853210, 854210, 854310, 854320, 854321, 863210, 864210, 864310, 864320, 864321, 865210, 865310, 865320, 865321, 865410, 865420, 865421, 865430, 865431, 865432, 873210, 874210, 874310, 874320, 874321, 875210, 875310, 875320, 875321, 875410, 875420, 875421, 875430, 875431, 875432, 876210, 876310, 876320, 876321, 876410, 876420, 876421, 876430, 876431, 876432, 876510, 876520, 876521, 876530, 876531, 876532, 876540, 876541, 876542, 876543, 943210, 953210, 954210, 954310, 954320, 954321, 963210, 964210, 964310, 964320, 964321, 965210, 965310, 965320, 965321, 965410, 965420, 965421, 965430, 965431, 965432, 973210, 974210, 974310, 974320, 974321, 975210, 975310, 975320, 975321, 975410, 975420, 975421, 975430, 975431, 975432, 976210, 976310, 976320, 976321, 976410, 976420, 976421, 976430, 976431, 976432, 976510, 976520, 976521, 976530, 976531, 976532, 976540, 976541, 976542, 976543, 983210, 984210, 984310, 984320, 984321, 985210, 985310, 985320, 985321, 985410, 985420, 985421, 985430, 985431, 985432, 986210, 986310, 986320, 986321, 986410, 986420, 986421, 986430, 986431, 986432, 986510, 986520, 986521, 986530, 986531, 986532, 986540, 986541, 986542, 986543, 987210, 987310, 987320, 987321, 987410, 987420, 987421, 987430, 987431, 987432, 987510, 987520, 987521, 987530, 987531, 987532, 987540, 987541, 987542, 987543, 987610, 987620, 987621, 987630, 987631, 987632, 987640, 987641, 987642, 987643, 987650, 987651, 987652, 987653, 987654, 6543210, 7543210, 7643210, 7653210, 7654210, 7654310, 7654320, 7654321, 8543210, 8643210, 8653210, 8654210, 8654310, 8654320, 8654321, 8743210, 8753210, 8754210, 8754310, 8754320, 8754321, 8763210, 8764210, 8764310, 8764320, 8764321, 8765210, 8765310, 8765320, 8765321, 8765410, 8765420, 8765421, 8765430, 8765431, 8765432, 9543210, 9643210, 9653210, 9654210, 9654310, 9654320, 9654321, 9743210, 9753210, 9754210, 9754310, 9754320, 9754321, 9763210, 9764210, 9764310, 9764320, 9764321, 9765210, 9765310, 9765320, 9765321, 9765410, 9765420, 9765421, 9765430, 9765431, 9765432, 9843210, 9853210, 9854210, 9854310, 9854320, 9854321, 9863210, 9864210, 9864310, 9864320, 9864321, 9865210, 9865310, 9865320, 9865321, 9865410, 9865420, 9865421, 9865430, 9865431, 9865432, 9873210, 9874210, 9874310, 9874320, 9874321, 9875210, 9875310, 9875320, 9875321, 9875410, 9875420, 9875421, 9875430, 9875431, 9875432, 9876210, 9876310, 9876320, 9876321, 9876410, 9876420, 9876421, 9876430, 9876431, 9876432, 9876510, 9876520, 9876521, 9876530, 9876531, 9876532, 9876540, 9876541, 9876542, 9876543, 76543210, 86543210, 87543210, 87643210, 87653210, 87654210, 87654310, 87654320, 87654321, 96543210, 97543210, 97643210, 97653210, 97654210, 97654310, 97654320, 97654321, 98543210, 98643210, 98653210, 98654210, 98654310, 98654320, 98654321, 98743210, 98753210, 98754210, 98754310, 98754320, 98754321, 98763210, 98764210, 98764310, 98764320, 98764321, 98765210, 98765310, 98765320, 98765321, 98765410, 98765420, 98765421, 98765430, 98765431, 98765432, 876543210, 976543210, 986543210, 987543210, 987643210, 987653210, 987654210, 987654310, 987654320, 987654321, 9876543210};

int main()
{
    ll K;
    cin >> K;
    cout << ans[K - 1] << endl;
}
