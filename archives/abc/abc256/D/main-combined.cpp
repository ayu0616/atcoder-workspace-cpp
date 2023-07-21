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
#line 2 "abc256/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

vector<pair<ll, ll>> ans, lr;
ll l, r;

void add(ll x, ll y, vector<pair<ll, ll>> &v)
{
    bool need_add = true;

    for (auto &p : v)
    {
        if (y < p.first || p.second < x)
            continue;
        else
        {
            p.first = min(p.first, x);
            p.second = max(p.second, y);
            need_add = false;
        }
    }
    if (need_add)
        v.push_back({x, y});
}

int main()
{
    ll n;
    cin >> n;
    rep(i, n)
    {
        cin >> l >> r;
        lr.push_back({l, r});
    }
    sort(lr.begin(), lr.end());
    for (auto p : lr)
    {
        add(p.first, p.second, ans);
    }
    for (auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
}
