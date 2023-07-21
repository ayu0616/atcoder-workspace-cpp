#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll n, m, k;
vl p, h;

int main()
{
    cin >> n >> m >> k;
    Graph g(n);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        g.add_edge(a, b, false);
    }
    p.resize(k), h.resize(k);
    rep(i, k) cin >> p[i] >> h[i], p[i]--;

    vl max_h(n, -1);
    priority_queue<pll> q;
    rep(i, k) max_h[p[i]] = max(max_h[p[i]], h[i]), q.push({max_h[p[i]], p[i]});
    while (!q.empty())
    {
        auto [h, v] = q.top();
        q.pop();
        if (max_h[v] != h)
            continue;
        for (auto &e : g[v])
        {
            if (max_h[e.to] < h - 1)
            {
                max_h[e.to] = max(max_h[e.to], h - 1);
                q.push({max_h[e.to], e.to});
            }
        }
    }
    ll ans = 0;
    vi ans_v;
    rep(i, n)
    {
        if (max_h[i] >= 0)
        {
            ans++;
            ans_v.push_back(i + 1);
        }
    }
    cout << ans << endl;
    sort(all(ans_v));
    print(ans_v);
}
