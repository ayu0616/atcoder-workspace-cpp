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
#line 2 "abc259/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<vector<ll>> c(n, vector<ll>(3));
    rep(i, n) cin >> c[i][0] >> c[i][1] >> c[i][2];
    ll cs, ct;
    if (powl(sx - c[n - 1][0], 2) + powl(sy - c[n - 1][1], 2) == powl(c[n - 1][2], 2))
        cs = n - 1;
    if (powl(tx - c[n - 1][0], 2) + powl(ty - c[n - 1][1], 2) == powl(c[n - 1][2], 2))
        ct = n - 1;
    UnionFind uf(n);
    for (int i = 0; i < n - 1; i++)
    {
        if (powl(sx - c[i][0], 2) + powl(sy - c[i][1], 2) == powl(c[i][2], 2))
            cs = i;
        if (powl(tx - c[i][0], 2) + powl(ty - c[i][1], 2) == powl(c[i][2], 2))
            ct = i;
        for (int j = i + 1; j < n; j++)
        {
            ll c_dist = powl(c[i][0] - c[j][0], 2) + powl(c[i][1] - c[j][1], 2);
            ll r_sum = powl(c[i][2] + c[j][2], 2);
            ll r_diff = powl(c[i][2] - c[j][2], 2);
            if (c_dist <= r_sum && c_dist >= r_diff)
            {
                uf.unite(i, j);
            }
        }
    }
    string ans = (uf.same(cs, ct)) ? "Yes" : "No";
    cout << ans << endl;
}
