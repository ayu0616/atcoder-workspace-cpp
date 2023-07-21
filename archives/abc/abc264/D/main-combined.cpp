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
#line 2 "abc264/D/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

string s;
string atcoder = "atcoder";
int ans = 0;

int main()
{
    cin >> s;
    rep(i, 7)
    {
        int pos = 0;
        rep(j, s.size())
        {
            if (s[j] == atcoder[i])
            {
                pos = j;
                break;
            }
        }
        // cout << s << " " << pos << " " << atcoder[i] << endl;
        ans += pos - i;
        string tmp = "";
        for (int j = 0; j < i; j++)
        {
            tmp += s[j];
        }
        tmp += atcoder[i];
        for (int j = i; j < 7; j++)
        {
            if (j != pos)
                tmp += s[j];
        }
        s = tmp;
    }
    cout << ans << endl;
}
