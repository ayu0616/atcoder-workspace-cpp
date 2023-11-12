#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

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

// @brief ヒープ（小さい順）
template <typename T>
class greater_heap : priority_queue<T, vector<T>, greater<T>>
{
public:
    bool not_empty()
    {
        return !this->empty();
    }

    void print_all()
    {
        while (not_empty())
        {
            cout << this->top() << endl;
            this->pop();
        }
    }
};

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

struct Edge;

// @brief グラフの頂点
struct Vertex
{
    ll id;
    vector<Edge> edges;

    Vertex(ll id)
    {
        this->id = id;
        this->edges = vector<Edge>();
    }

    operator ll() const
    {
        return this->id;
    }
};

// @brief グラフの辺
// @param to 辺の行き先
// @param cost 辺のコスト
struct Edge
{
    Vertex *from, *to;
    ll cost;

    Edge(ll from, ll to, ll cost = 1)
    {
        this->from = new Vertex(from);
        this->to = new Vertex(to);
        this->cost = cost;
    }

    Edge(Vertex *from, Vertex *to, ll cost = 1)
    {
        this->from = from;
        this->to = to;
        this->cost = cost;
    }
};

// @brief グラフ
class Graph : vector<Vertex>
{
    ll n;

public:
    Graph(ll n)
    {
        this->n = n;
        rep(i, n) this->push_back(Vertex(i));
    }

    void add_edge(ll from, ll to, ll cost = 1)
    {
        Vertex &u = this->at(from);
        Vertex &v = this->at(to);
        Edge e(u, v, cost);
        u.edges.push_back(e);
    }

    // @brief ダイクストラ法
    // @param start 始点
    // @return 始点からの最短距離（到達不可能な点への距離は-1とする）
    vl dyjkstra(ll start)
    {
        vl dist(n, LLONG_MAX);
        dist[start] = 0;
        priority_queue<pll, vpll, greater<pll>> que;
        que.push({0, start});
        while (!que.empty())
        {
            pll p = que.top();
            que.pop();
            ll v = p.second;
            if (dist[v] < p.first)
                continue;
            for (auto e : this->at(v).edges)
            {
                if (dist[*e.to] > dist[v] + e.cost)
                {
                    dist[*e.to] = dist[v] + e.cost;
                    que.push({dist[*e.to], *e.to});
                }
            }
        }
        rep(i, n) if (dist[i] == LLONG_MAX) dist[i] = -1;
        return dist;
    }

    // @brief ワーシャルフロイド法
    // @return 全点間の最短距離（到達不可能な点への距離は-1とする）
    vvl warshall_floyd()
    {
        vvl dist(n, vl(n, LLONG_MAX));
        rep(i, n) dist[i][i] = 0;
        rep(i, n)
        {
            for (auto e : this->at(i).edges)
            {
                dist[i][*e.to] = e.cost;
            }
        }
        rep(k, n)
        {
            rep(i, n)
            {
                rep(j, n)
                {
                    if (dist[i][k] != LLONG_MAX && dist[k][j] != LLONG_MAX)
                    {
                        chmin(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        rep(i, n) rep(j, n) if (dist[i][j] == LLONG_MAX) dist[i][j] = -1;
        return dist;
    }

    // @brief ベルマンフォード法
    // @param start 始点
    // @return 始点からの最短距離（到達不可能な点への距離は-1とする）
    vl bellman_ford(ll start)
    {
        vl dist(n, LLONG_MAX);
        dist[start] = 0;
        rep(i, n)
        {
            rep(j, n)
            {
                for (auto e : this->at(j).edges)
                {
                    if (dist[j] != LLONG_MAX && dist[*e.to] > dist[j] + e.cost)
                    {
                        dist[*e.to] = dist[j] + e.cost;
                        if (i == n - 1)
                            dist[*e.to] = LLONG_MIN;
                    }
                }
            }
        }
        rep(i, n) if (dist[i] == LLONG_MAX) dist[i] = -1;
        return dist;
    }

    vector<Edge> operator[](ll id)
    {
        return this->at(id).edges;
    }
};

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
istream &operator>>(istream &is, vector<T> &v)
{
    rep(i, v.size()) is >> v[i];
    return is;
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

template <class T>
ostream &operator<<(ostream &os, set<T> &s)
{
    ll i = 0;
    for (T v : s)
    {
        cout << v;
        if (i++ < s.size() - 1)
            os << " ";
    }
    return os;
}

template <class T>
ostream &operator<<(ostream &os, priority_queue<T> q)
{
    ll i = 0;
    while (!q.empty())
    {
        cout << q.top();
        q.pop();
        if (i++ < q.size() - 1)
            os << " ";
    }
    return os;
}
template <class T>
ostream &operator<<(ostream &os, greater_heap<T> q)
{
    ll i = 0;
    while (!q.empty())
    {
        cout << q.top();
        q.pop();
        if (i++ < q.size() - 1)
            os << " ";
    }
    return os;
}

template <class T, class S>
ostream &operator<<(ostream &os, pair<T, S> p)
{
    os << p.first << " " << p.second;
    return os;
}

template <typename T>
void print(T v)
{
    cout << v << endl;
}

void dfs_combination(int n, int r, int from, vi &use, vvi &uses)
{
    if (from + r > n)
    {
        return;
    }
    else if (r == 0)
    {
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
vector<vector<T>> combinations(vector<T> &v, int r)
{
    int n = v.size();
    vi use;
    vvi uses;
    dfs_combination(n, r, 0, use, uses);
    vector<vector<T>> res(uses.size());
    rep(i, uses.size())
    {
        vi &u = uses[i];
        vector<T> tmp;
        for (auto &i : u)
        {
            tmp.push_back(v[i]);
        }
        res[i] = tmp;
    }
    return res;
}
#line 2 "abc240/E/main.cpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vvi G;
vi deg;
vector<bool> visited;
vpii ans;
int cnt = 0;

void dfs(int v)
{
    if (visited[v])
        return;
    visited[v] = true;
    if (v != 0 && deg[v] == 1)
    {
        cnt++;
        ans[v] = {cnt, cnt};
        return;
    }
    for (auto u : G[v])
    {
        if (visited[u])
            continue;
        dfs(u);
        ans[v].first = min(ans[v].first, ans[u].first);
        ans[v].second = max(ans[v].second, ans[u].second);
    }
}

int main()
{
    int N;
    cin >> N;
    G.resize(N);
    deg.resize(N);
    rep(i, N - 1)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    visited = vector<bool>(N, false);
    ans = vpii(N, {1e9, 0});
    dfs(0);
    rep(i, N)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}
