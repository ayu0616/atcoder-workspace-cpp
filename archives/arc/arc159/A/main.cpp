#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, q;
    ll k, s, t;
    cin >> n >> k;
    vvi a(n, vi(n)), x(2 * n, vi(2 * n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n)
    {
        x[i][j] = a[i][j];
        x[i + n][j] = a[i][j];
        x[i][j + n] = a[i][j];
        x[i + n][j + n] = a[i][j];
    }
    cin >> q;
    rep(i, q)
    {
        cin >> s >> t;
        if (s == t)
        {
            cout << 0 << endl;
            continue;
        }
        s--, t--;
        s %= n, t %= n;
        t += n;

        deque<int> que;
        que.push_back(s);
        vi dist(2 * n, -1);
        dist[s] = 0;
        while (!que.empty())
        {
            int v = que.front();
            que.pop_front();
            for (int nv = 0; nv < 2*n; ++nv)
            {
                if (x[v][nv] == 0)
                    continue;
                if (dist[nv] != -1)
                    continue;
                dist[nv] = dist[v] + 1;
                que.push_back(nv);
            }
        }
        cout << dist[t] << endl;
    }
}
