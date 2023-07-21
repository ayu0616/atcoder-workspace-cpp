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
#line 2 "abc298/E/main.cpp"

// #define MOD 1000000007
#define MOD 998244353

int n, a, b, p, q;
ll dp_a[110][111], dp_b[110][111], ta[110], tb[110];

long long modinv(long long a, long long m)
{
    long long b = m, u = 1, v = 0;
    while (b)
    {
        long long t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}

int main()
{
    cin >> n >> a >> b >> p >> q;
    dp_a[0][a] = 1;
    rep(i, 110) ta[i] = 0, tb[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = a; j < n; j++)
        {
            for (int k = 1; k <= p; k++)
            {
                if (j + k >= n)
                {
                    ta[i + 1] += dp_a[i][j];
                    ta[i + 1] %= MOD;
                }
                else
                {
                    dp_a[i + 1][j + k] += dp_a[i][j];
                    dp_a[i + 1][j + k] %= MOD;
                }
            }
        }
    }
    dp_b[0][b] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = b; j < n; j++)
        {
            for (int k = 1; k <= q; k++)
            {
                if (j + k >= n)
                {
                    tb[i + 1] += dp_b[i][j];
                    tb[i + 1] %= MOD;
                }
                else
                {
                    dp_b[i + 1][j + k] += dp_b[i][j];
                    dp_b[i + 1][j + k] %= MOD;
                }
            }
        }
    }
    ll ga[110], gb[110], all = 0, win = 0, lose = 0;
    rep(i, 110)
    {
        ga[i] = 0;
        gb[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ga[i] = ta[i];
            gb[i] = tb[i];
        }
        else
        {
            ga[i] = ga[i - 1] + ta[i];
            gb[i] = gb[i - 1] + tb[i];
            ga[i] %= MOD;
            gb[i] %= MOD;
        }
    }
    for (int i = 1; i < n; i++)
    {
        win += (ga[i] - ga[i - 1]) * (gb[n - 1] - gb[i - 1]);
        win %= MOD;
        lose += (gb[i] - gb[i - 1]) * (ga[n - 1] - ga[i]);
        lose %= MOD;
    }
    all = (win + lose) % MOD;
    cout << (modinv(all, MOD) * win) % MOD << endl;
    // cout << win << " " << all << endl;
    // rep(i, n)
    // {
    //     cout << ga[i] << " ";
    // }
    // cout << endl;
    // rep(i, n)
    // {
    //     cout << gb[i] << " ";
    // }
    // cout << endl;
}
