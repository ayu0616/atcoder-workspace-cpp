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
#line 2 "abc266/C/main.cpp"

// #define MOD 1000000007
// #define MOD 998244353

int nodes[4][2];
string ans;
int i, j, k;
double s, co;
int ab[2], ad[2];

const double EPS = 1e-9;

double vec_abs(int vec[2])
{
    return sqrt(vec[0] * vec[0] + vec[1] * vec[1]);
}

int vec_dot(int vec1[2], int vec2[2])
{
    return vec1[0] * vec2[0] + vec1[1] * vec2[1];
}

int main()
{
    rep(i, 4)
    {
        cin >> nodes[i][0] >> nodes[i][1];
    }
    ans = "Yes";
    s = 0.0;

    rep(i, 4)
    {
        j = (i + 1);
        k = (i - 1);
        if (j > 3)
            j -= 4;
        if (k < 0)
            k += 4;
        // cout << i << " " << j << " " << k << endl;
        rep(l, 2)
        {
            ab[l] = nodes[j][l] - nodes[i][l];
            ad[l] = nodes[k][l] - nodes[i][l];
        }
        // cout << vec_dot(ab, ad) << " " << vec_abs(ab) << " " << vec_abs(ad) << endl;
        co = vec_dot(ab, ad) / (vec_abs(ab) * vec_abs(ad));
        s += acos(co);
    }
    if (2 * M_PI - s < EPS)
    {
        ans = "Yes";
    }
    else
    {
        ans = "No";
    }
    cout << ans << endl;
}
