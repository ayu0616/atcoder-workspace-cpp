#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, x, y;
    // cin >> n;
    cin >> n >> x >> y;
    Graph g = Graph(n - 1);
    deque<int> q;
    deque<int> ans;
    q.push_back(x);
    int visited[n + 1];
    rep(i, n + 1) visited[i] = 0;
    bool stop = false;

    while (!q.empty())
    {
        int now = q.back();
        q.pop_back();
        ans.push_back(now);
        visited[now] = 1;
        if (now == y)
            break;
        stop = true;
        for (int u : g.edges[now])
        {
            if (visited[u])
                continue;
            stop = false;
            q.push_back(u);
        }
        if (stop)
        {
            ans.pop_back();
        }
    }

    rep(i, ans.size())
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
    }
    cout << endl;
}
