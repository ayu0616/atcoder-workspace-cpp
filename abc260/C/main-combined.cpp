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
#line 2 "abc260/C/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, x, y;
ll r(int k);
ll b(int k);

ll stones[11][2];

ll r(int k)
{
    if (n == k)
    {
        return 1;
    }
    else
    {
        return r(k + 1) + b(k + 1);
    }
}

ll b(int k)
{
    if (n == k)
    {
        return x * r(k);
    }
    else
    {
        return (x + y) * r(k) + y * r(k + 1);
    }
}

int main()
{
    cin >> n >> x >> y;
    rep(i, 11) rep(j, 2) stones[i][j] = 0;
    stones[n][0] = 1;
    for (int i = n; i >= 2; i--)
    {
        stones[i][1] += stones[i][0] * x;
        stones[i - 1][0] += stones[i][0];
        stones[i][0] = 0;

        stones[i - 1][0] += stones[i][1];
        stones[i - 1][1] += stones[i][1] * y;
        stones[i][1] = 0;
    }
    cout << stones[1][1] << endl;
    // show_multi_array(stones, 11, 2);
}
