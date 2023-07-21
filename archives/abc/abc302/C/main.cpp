#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) { cin >> s[i]; }

    Graph<int> g;
    rep(i, n) rep(j, n)
    {
        int score = 0;
        rep(k, m)
        {
            if (s[i][k] != s[j][k])
            {
                score++;
            }
        }
        if (score == 1)
        {
            g[i].insert(j);
            g[j].insert(i);
        }
    }

    rep(i, n)
    {
        vi visited(n, 0);
        visited[i] = 1;
        deque<int> q;
        q.push_back(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop_front();
            for (auto next : g[cur])
            {
                if (visited[next] == 0)
                {
                    visited[next] = 1;
                    q.push_front(next);
                }
            }
        }
        bool ok = true;
        rep(j, n)
        {
            if (visited[j] == 0)
            {
                ok = false;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
