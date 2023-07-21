#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n, m, u, v, k, p, d, color[2001];
vector<pair<int, int>> cond;
deque<int> q;
vector<vector<int>> b_cand;

int main()
{
    cin >> n >> m;
    Graph<int> g;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        g[u].insert(v);
        g[v].insert(u);
    }
    cin >> k;
    rep(i, k)
    {
        cin >> p >> d;
        p--;
        cond.push_back({p, d});
    }
    rep(i, n) color[i] = -1;
    int dist[2001];
    for (auto c : cond)
    {
        b_cand.push_back(vector<int>());
        rep(i, n) dist[i] = 10000;
        q.clear();
        p = c.first;
        d = c.second;
        q.push_back(p);
        dist[p] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop_front();
            if (dist[now] < d)
            {
                if (color[now] == 1)
                {
                    cout << "No" << endl;
                    return 0;
                }
                else
                {
                    color[now] = 0;
                }
            }
            else if (dist[now] == d)
                b_cand.back().push_back(now);
            else
                break;
            for (auto next : g[now])
            {
                if (dist[next] == 10000)
                {
                    dist[next] = dist[now] + 1;
                    q.push_back(next);
                }
            }
        }
        if (b_cand.back().size() == 1)
        {
            if (color == 0)
            {
                cout << "No" << endl;
                return 0;
            }
            color[b_cand.back()[0]] = 1;
            b_cand.pop_back();
        }
    }
    for (auto v : b_cand)
    {
        vector<int> bl, wh, fr;
        for (auto p : v)
        {
            if (color[p] == 1)
                bl.push_back(p);
            else if (color[p] == 0)
                wh.push_back(p);
            else
                fr.push_back(p);
        }
        if (bl.size() + fr.size() == 0)
        {
            cout << "No" << endl;
            return 0;
        }
        for (auto p : fr)
        {
            color[p] = 1;
        }
    }
    cout << "Yes" << endl;
    rep(i, n)
    {
        if (color[i] == -1)
            color[i] = 1;
        cout << color[i];
    }
    cout << endl;
}
