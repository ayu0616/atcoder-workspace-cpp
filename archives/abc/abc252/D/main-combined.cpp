#line 1 "lib.hpp"
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define rep(i, n) for (ll i = 0; i < (int)(n); i++)

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

class Graph
{
public:
    unordered_map<int, set<int>> edges;

    /* n: 枝の数
    directed: 有向グラフかどうか
     */
    Graph(int n, bool directed = false)
    {
        rep(_, n)
        {
            int u, v;
            cin >> u >> v;
            this->edges[u].insert(v);
            if (!directed)
            {
                this->edges[v].insert(u);
            }
        }
    }
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
#line 2 "abc252/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int upper = 200010;
    ll cnt[upper];
    rep(i, upper) cnt[i] = 0;
    rep(i, n) cnt[a[i]]++;
    rep(i, upper) cnt[i + 1] += cnt[i];

    ll ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans += cnt[a[j] - 1] * (n - cnt[a[j]]);
    }

    cout << ans << endl;
}
