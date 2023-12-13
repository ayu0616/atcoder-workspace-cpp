#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    vvi g(n1 + n2);
    rep(_, m)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vi d1(n1 + n2, 1e9), d2(n1 + n2, 1e9);
    deque<int> q;
    q.push_back(0);
    d1[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (int u : g[v])
        {
            if (d1[u] > d1[v] + 1)
            {
                d1[u] = d1[v] + 1;
                q.push_back(u);
            }
        }
    }

    q.push_back(n1 + n2 - 1);
    d2[n1 + n2 - 1] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop_front();
        for (int u : g[v])
        {
            if (d2[u] > d2[v] + 1)
            {
                d2[u] = d2[v] + 1;
                q.push_back(u);
            }
        }
    }

    int d1_max = 0, d2_max = 0;
    rep(i, n1 + n2)
    {
        if (d1[i] != 1e9)
            chmax(d1_max, d1[i]);
        if (d2[i] != 1e9)
            chmax(d2_max, d2[i]);
    }
    cout << d1_max + d2_max + 1 << endl;
}
