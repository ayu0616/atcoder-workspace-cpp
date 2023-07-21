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
#line 2 "abc258/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int n, x, stage;
ll ans;
ll a[200000 + 10], b[200000 + 10], sa[200000 + 10], sb[200000 + 10];

int main()
{
    cin >> n >> x;
    int stage = 0;
    a[0] = 0;
    b[0] = 0;
    sa[0] = 0;
    sb[0] = 0;
    rep(i, n)
    {
        cin >> a[i + 1] >> b[i + 1];
        sa[i + 1] = sa[i] + a[i + 1];
        sb[i + 1] = sb[i] + b[i + 1];
    }
    ans = 1e19;
    for (ll i = 1; i <= min(n, x); i++)
    {
        ans = min(ans, sa[i] + sb[i] + (x - i) * b[i]);
    }
    cout << ans << endl;
}
