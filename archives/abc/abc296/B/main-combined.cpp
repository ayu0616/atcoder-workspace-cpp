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
#line 2 "abc296/B/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

vector<char> a, b;

int main()
{
    for (int i = 'a'; i <= 'h'; i++)
    {
        a.push_back((char)i);
    }
    for (int i = '8'; i >= '1'; i--)
    {
        b.push_back((char)i);
    }
    vector<string> s;
    string tmp;
    while (cin >> tmp)
    {
        s.push_back(tmp);
    }
    int n = 8;
    rep(i, n) rep(j, n)
    {
        if (s[i][j] == '*')
        {
            cout << (char)a[j] << (char)b[i] << endl;
        }
    }
}
