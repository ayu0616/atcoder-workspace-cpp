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
#line 2 "abc271/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, s;
    cin >> n >> s;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    rep(i, n + 1) rep(j, s + 1)
    {
        if (i == 0 && j == 0)
        {
            dp[i][j] = true;
            continue;
        }
        if (i == 0)
        {
            continue;
        }
        if (j + a[i - 1] <= s && dp[i - 1][j])
        {
            dp[i][j + a[i - 1]] = true;
        }
        if (j + b[i - 1] <= s && dp[i - 1][j])
        {
            dp[i][j + b[i - 1]] = true;
        }
    }
    // rep(i, n + 1) rep(j, s + 1) cout << dp[i][j] << " \n"[j == s];

    if (dp[n][s])
    {
        cout << "Yes" << endl;
        vector<char> ans(n);
        for (int i = n; i > 0; i--)
        {
            if (s - a[i - 1] >= 0 && dp[i - 1][s - a[i - 1]])
            {
                ans[i - 1] = 'H';
                s -= a[i - 1];
                continue;
            }
            if (s - b[i - 1] >= 0 && dp[i - 1][s - b[i - 1]])
            {
                ans[i - 1] = 'T';
                s -= b[i - 1];
                continue;
            }
        }
        rep(i, n) cout << ans[i];
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
