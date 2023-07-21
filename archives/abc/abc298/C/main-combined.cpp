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
#line 2 "abc298/C/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, q;

int main()
{
    cin >> n >> q;
    vector<priority_queue<ll, vector<ll>, greater<ll>>> v(200000);
    vector<set<ll>> s(200000);
    int type;
    rep(i, q)
    {
        cin >> type;
        if (type == 1)
        {
            ll a, b;
            cin >> a >> b;
            a--, b--;
            v[b].push(a);
            s[a].insert(b);
        }
        else if (type == 2)
        {
            ll a;
            cin >> a;
            a--;
            auto tmp = v[a];
            while (!tmp.empty())
            {
                cout << tmp.top() + 1 << " \n"[tmp.size() == 1];
                tmp.pop();
            }
        }
        else
        {
            ll a;
            cin >> a;
            a--;
            ll cnt = 1;
            for (auto x : s[a])
            {
                cout << x + 1 << " \n"[cnt == s[a].size()];
                cnt++;
            }
        }
    }
}
