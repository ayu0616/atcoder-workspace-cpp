#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

template <class T>
void vector_in(vector<T> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        T x;
        cin >> x;
        v.push_back(x);
    }
}

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
#line 2 "abc138/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

bool visited[200010];
Graph<int> tree;
map<int, ll> m;
ll ans[200010];

void solve(int node)
{
    visited[node] = true;
    for (auto nv : tree[node])
    {
        if (visited[nv])
            continue;
        ans[nv] += ans[node] + m[nv];
        solve(nv);
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    Graph<int> g;
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].insert(b);
        g[b].insert(a);
    }
    rep(i, n) visited[i] = false;
    queue<int> que;
    que.push(0);
    visited[0] = true;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : g[v])
        {
            if (visited[nv])
                continue;
            visited[nv] = true;
            tree[v].insert(nv);
            que.push(nv);
        }
    }

    rep(i, q)
    {
        int p, x;
        cin >> p >> x;
        p--;
        m[p] += x;
    }

    rep(i, n)
    {
        ans[i] = 0;
        visited[i] = false;
    }

    ans[0] = m[0];
    solve(0);

    rep(i, n) cout << ans[i] << " \n"[i == n - 1];
    // cout << endl;
}
