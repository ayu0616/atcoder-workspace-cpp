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
#line 2 "abc257/C/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, c;
    string s;
    ll w;
    vector<pair<ll, char>> p;
    cin >> n >> s;

    int ans = 0;
    rep(i, n)
    {
        cin >> w;
        p.push_back({w, s[i]});
        if (s[i] == '1')
            ans++;
    }

    sort(p.begin(), p.end());

    c = ans;
    rep(i, n)
    {
        if (p[i].second == '1')
            c--;
        else
            c++;
        if (i < (n - 1) && p[i].first == p[i + 1].first)
            continue;
        ans = max(ans, c);
    }
    cout << ans << endl;
}
