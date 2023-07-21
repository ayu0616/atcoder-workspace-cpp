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
#line 2 "abc261/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

ll max_vec(vector<ll> v)
{
    ll max = 0;
    for (auto i : v)
    {
        if (i > max)
        {
            max = i;
        }
    }
    return max;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    map<int, ll> bonus;
    rep(i, m)
    {
        int c;
        ll y;
        cin >> c >> y;
        bonus[c] = y;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    dp[1][1] = x[0] + bonus[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
            {
                dp[i][j] = max_vec(dp[i - 1]);
            }
            else
            {
                if (dp[i - 1][j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + x[i - 1] + bonus[j];
                }
            }
            // cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    cout << max_vec(dp[n]) << endl;
}
