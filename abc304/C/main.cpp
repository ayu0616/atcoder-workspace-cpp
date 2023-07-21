#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, d;
    cin >> n >> d;
    vi x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    Graph g(n);
    int d_2 = pow(d, 2);

    rep(i, n) rep2(j, i + 1, n)
    {
        if (i == j)
            continue;
        if (pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2) <= d_2)
        {
            g.add_edge(i, j);
        }
    }

    vector<bool> infected(n, false);
    infected[0] = true;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto nv : g[v])
        {
            if (infected[nv])
                continue;
            infected[nv] = true;
            q.push(nv);
        }
    }
    rep(i, n) cout << (infected[i] ? "Yes" : "No") << endl;
}
