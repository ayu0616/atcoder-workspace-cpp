#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<set<int>> s(n);
    Graph<int> g;
    rep(i, n)
    {
        int a;
        cin >> a;
        rep(j, a)
        {
            int b;
            cin >> b;
            s[i].insert(b);
            g[b].insert(i);
        }
    }

    vi dist(m + 1, -1), visited_set(n, 0);
    deque<int> q;
    q.push_back(1);
    dist[1] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop_front();
        for (auto next_set : g[cur])
        {
            if (visited_set[next_set] == 0)
            {
                visited_set[next_set] = 1;
                for (auto next_num : s[next_set])
                {
                    if (dist[next_num] == -1)
                    {
                        dist[next_num] = dist[cur] + 1;
                        q.push_back(next_num);
                    }
                }
            }
        }
    }
    if(dist[m]!=-1)
        dist[m]--;
    cout << dist[m] << endl;
}
