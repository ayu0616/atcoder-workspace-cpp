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
#line 2 "abc264/C/main.cpp"

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

    for (int bit1 = 0; bit1 < (1 << h1); ++bit1)
    {
        vector<vector<ll>> tmp1 = a;
        int cnt1 = 0;
        rep(i, h1) if (bit1 & (1 << i)) cnt1++;
        cnt1 = 0;
        rep(i, h1) if (bit1 & (1 << i))
        {
            del_row(i - cnt1);
            cnt1++;
        }

        for (int bit2 = 0; bit2 < (1 << w1); ++bit2)
        {
            vector<vector<ll>> tmp2 = a;
            int cnt2 = 0;
            rep(i, w1) if (bit2 & (1 << i)) cnt2++;
            if (cnt1 != del_row_cnt || cnt2 != del_col_cnt)
                continue;

            cnt2 = 0;
            rep(i, w1) if (bit2 & (1 << i))
            {
                del_col(i - cnt2);
                cnt2++;
            }

            if (is_eq())
            {
                cout << "Yes" << endl;
                return 0;
            }
            a = tmp2;
        }
        a = tmp1;
    }
    cout << "No" << endl;
}
