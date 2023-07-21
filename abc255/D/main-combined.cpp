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
void show_array(T arr[], int n)
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
void show_multi_array(T arr[], int n, int m)
{
    rep(i, n)
    {
        show_array(arr[i], m);
    }
}
#line 2 "abc255/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n, q, x;
    vector<ll> a, sa, X, X_sorted;
    map<ll, ll> ans;
    cin >> n >> q;
    vector_in(a, n);
    vector_in(X, q);
    sort(a.begin(), a.end());
    sa.push_back(0);
    rep(i, n)
    {
        sa.push_back(sa[i] + a[i]);
    }
    X_sorted = X;
    sort(X_sorted.begin(), X_sorted.end());

    ll index = 0;
    rep(i, q)
    {
        x = X_sorted[i];
        while (index < n && a[index] <= x)
        {
            index++;
        }
        ans[x] = 2 * x * index - 2 * sa[index] + sa[n] - x * n;
    }
    rep(i, q)
    {
        cout << ans[X[i]] << endl;
    }
}
