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
#line 2 "abc264/G/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int h1, w1, h2, w2;
vector<vector<ll>> a, b;

bool is_eq()
{
    if (a.size() != b.size())
        return false;
    if (a[0].size() != b[0].size())
        return false;
    rep(i, a.size()) rep(j, a[0].size()) if (a[i][j] != b[i][j]) return false;
    return true;
}

void del_row(int row)
{
    vector<vector<ll>> tmp;
    rep(i, a.size()) if (i != row) tmp.push_back(a[i]);
    a = tmp;
}

void del_col(int col)
{
    vector<vector<ll>> tmp;
    rep(i, a.size())
    {
        vector<ll> tmp2;
        rep(j, a[0].size()) if (j != col) tmp2.push_back(a[i][j]);
        tmp.push_back(tmp2);
    }
    a = tmp;
}

int main()
{
    cin >> h1 >> w1;
    a.resize(h1, vector<ll>(w1));
    rep(i, h1) rep(j, w1) cin >> a[i][j];
    cin >> h2 >> w2;
    b.resize(h2, vector<ll>(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    int del_row_cnt = h1 - h2;
    int del_col_cnt = w1 - w2;

    int rows[del_row_cnt], cols[del_col_cnt];

    rep(i, del_row_cnt) rows[i] = i;
    rep(i, del_col_cnt) cols[i] = i;

    do
    {
        do
        {
            vector<vector<ll>> tmp = a;
            rep(i, del_row_cnt) del_row(rows[i]);
            rep(i, del_col_cnt) del_col(cols[i]);
            if (is_eq())
            {
                cout << "Yes" << endl;
                return 0;
            }
            a = tmp;
        } while (next_permutation(cols, cols + del_col_cnt));
    } while (next_permutation(rows, rows + del_row_cnt));
    cout << "No" << endl;
}
