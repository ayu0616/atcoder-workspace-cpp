#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using heapi = priority_queue<int, vector<int>, greater<int>>;
using heapl = priority_queue<long long, vector<long long>, greater<long long>>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, a, b) for (int i = (a); i < (int)(b); i++)

/* グラフ */
class Graph
{
private:
    vvl _weight;

public:
    int n;
    vector<set<int>> neighbor_list;

    // @brief コンストラクタ
    // @param n 頂点数
    Graph(int n) : n(n)
    {
        neighbor_list.resize(n);
        _weight.resize(n, vl(n, 0));
    }

    // @brief 枝の追加
    // @param u, v 枝の端点
    // @param directed 有向グラフの場合はtrue
    void add_edge(int u, int v, bool directed = false, ll weight = 1)
    {
        neighbor_list[u].insert(v);
        _weight[u][v] = weight;
        if (!directed)
            neighbor_list[v].insert(u);
        _weight[v][u] = weight;
    }

    // @brief 枝の削除
    // @param u, v 枝の端点
    // @param directed 有向グラフの場合はtrue
    void remove_edge(int u, int v, bool directed = false)
    {
        neighbor_list[u].erase(v);
        _weight[u][v] = 0;
        if (!directed)
            neighbor_list[v].erase(u);
        _weight[v][u] = 0;
    }

    // @brief 頂点の削除
    // @param u 頂点
    void remove_node(int u)
    {
        for (auto v : neighbor_list[u])
        {
            neighbor_list[v].erase(u);
            _weight[v][u] = 0;
        }
        neighbor_list[u].clear();
        _weight[u].assign(n, 0);
    }

    // @brief ワーシャルフロイド法
    vvl floyd_warshall()
    {
        vvl dist(n, vl(n, 1e9));
        rep(i, n) dist[i][i] = 0;
        rep(u, n) for (auto v : neighbor_list[u]) dist[u][v] = _weight[u][v];
        rep(k, n) rep(i, n) rep(j, n) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist;
    }

    // @brief ダイクストラ法
    // @return 始点から各頂点への最短距離（パスが存在しなければ`1e18`）
    // @param s 始点
    vl dijkstra(int s)
    {
        vl dist(n, 1e18);
        dist[s] = 0;
        heapi q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.top();
            q.pop();
            for (auto v : neighbor_list[u])
            {
                if (dist[v] > dist[u] + _weight[u][v])
                {
                    dist[v] = dist[u] + _weight[u][v];
                    q.push(v);
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
        rep(u, n) for (auto v : neighbor_list[u]) in_degree[v]++;
        queue<int> q;
        rep(u, n) if (in_degree[u] == 0) q.push(u);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            sorted.push_back(u);
            for (auto v : neighbor_list[u])
            {
                in_degree[v]--;
                if (in_degree[v] == 0)
                    q.push(v);
            }
        }
        if (sorted.size() != n)
            sorted.clear();
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
                for (auto v : neighbor_list[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                        return false;
                }
            }
        }
        return true;
    }

    // @brief uに隣接する頂点の集合を返す
    // @param u 頂点
    set<int> &operator[](int u)
    {
        return neighbor_list[u];
    }
};

// 可変長引数のmin関数
template <class... T>
constexpr auto min(T... a)
{
    return min(initializer_list<common_type_t<T...>>{a...});
}

// 可変長引数のmax関数
template <class... T>
constexpr auto max(T... a)
{
    return max(initializer_list<common_type_t<T...>>{a...});
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

// 可変長引数の出力
template <class T, class... Ts>
void print(const T &a, const Ts &...b)
{
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}
#line 2 "abc304/E/main.cpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m, k, Q, p, q;
    cin >> n >> m;
    // Graph g(n);
    UnionFind uf(n);
    rep(i, m)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        // g.add_edge(u, v);
        uf.unite(u, v);
    }
    cin >> k;
    vi x(k), y(k);
    set<pair<int, int>> root_pair;
    rep(i, k)
    {
        cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        root_pair.insert({uf.root(x[i]), uf.root(y[i])});
        root_pair.insert({uf.root(y[i]), uf.root(x[i])});
    }
    cin >> Q;

    rep(i, Q)
    {
        cin >> p >> q;
        p--;
        q--;
        if (root_pair.find({uf.root(p), uf.root(q)}) != root_pair.end())
        {
            cout << "No" << endl;
        }
        else
        {
            cout << "Yes" << endl;
        }
    }
}
