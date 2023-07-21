#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

template <class T>
class Graph : public unordered_map<T, set<T>>
{
};

template <class T>
void show_array(T arr[], ll n)
{
    rep(i, n)
    {
        cout << arr[i];
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;
}

template <class T>
void show_multi_array(T arr[], ll n, ll m)
{
    rep(i, n)
    {
        show_array(arr[i], m);
    }
}

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

template <class T>
map<T, int> prime_factorize(T n)
{
    map<T, int> res;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n != 1)
    {
        res[n] = 1;
    }
    return res;
}

template <class T>
class UnionFind
{
    vector<T> par, rank, siz;

public:
    UnionFind(T n)
    {
        par = vector<T>(n, -1);
        rank = vector<T>(n, 0);
        siz = vector<T>(n, 1);
    }

    T root(T x)
    {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(T x, T y)
    {
        return root(x) == root(y);
    }

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

    T size(T x)
    {
        return siz[root(x)];
    }
};
#line 2 "abc299a/E/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int n, m, u, v, k, p, d, color[2001];
vector<pair<int, int>> cond;
deque<int> q;
vector<vector<int>> b_cand;

int main()
{
    cin >> n >> m;
    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    cin >> k;
    rep(i, k)
    {
        cin >> p >> d;
        p--;
        cond.push_back({p, d});
    }
    rep(i, n) color[i] = -1;
    int dist[2001];
    for (auto c : cond)
    {
        b_cand.push_back(vector<int>());
        rep(i, n) dist[i] = 10000;
        q.clear();
        p = c.first;
        d = c.second;
        q.push_back(p);
        dist[p] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            if (dist[now] < d)
            {
                if (color[now] == 1)
                {
                    cout << "No" << endl;
                    return 0;
                }
                else
                {
                    color[now] = 0;
                }
            }
            else if (dist[now] == d)
                b_cand.back().push_back(now);
            else
                break;
            for (auto next : g[now])
            {
                if (dist[next] == 10000)
                {
                    dist[next] = dist[now] + 1;
                    q.push_back(next);
                }
            }
        }
        if (b_cand.back().size() == 1)
        {
            if (color == 0)
            {
                cout << "No" << endl;
                return 0;
            }
            color[b_cand.back()[0]] = 1;
            b_cand.pop_back();
        }
    }
    for (auto v : b_cand)
    {
        vector<int> bl, wh, fr;
        for (auto p : v)
        {
            if (color[p] == 1)
                bl.push_back(p);
            else if (color[p] == 0)
                wh.push_back(p);
            else
                fr.push_back(p);
        }
        if (bl.size() + fr.size() == 0)
        {
            cout << "No" << endl;
            return 0;
        }
        for (auto p : fr)
        {
            color[p] = 1;
        }
    }
    cout << "Yes" << endl;
    rep(i, n)
    {
        if (color[i] == -1)
            color[i] = 1;
        cout << color[i];
    }
    cout << endl;
}
