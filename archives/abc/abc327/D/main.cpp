#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    cin >> N >> M;
    vl A(M), B(M);
    cin >> A >> B;
    Graph g(N);
    rep(i, M)
    {
        g.add_edge(A[i] - 1, B[i] - 1);
        g.add_edge(B[i] - 1, A[i] - 1);
    }
    vector<int> color(N, -1);
    rep(i, N)
    {
        if (color[i] != -1)
            continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto e : g[v])
            {
                int nv = e.to->id;
                if (color[nv] != -1)
                {
                    if (color[nv] == color[v])
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                    continue;
                }
                color[nv] = 1 - color[v];
                q.push(nv);
            }
        }
    }
    cout << "Yes" << endl;
}
