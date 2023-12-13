#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

void dfs(int i, int j, vector<string> &s, vector<vector<bool>> &visited, set<pii> &ans)
{
    visited[i][j] = true;
    rep(k, 4)
    {
        int x = i, y = j;
        while (s[x + dx4[k]][y + dy4[k]] == '.')
        {
            x += dx4[k], y += dy4[k];
            ans.insert({x, y});
        }
        if (!visited[x][y])
            dfs(x, y, s, visited, ans);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    set<pii> ans;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    ans.insert({1, 1});
    dfs(1, 1, s, visited, ans);
    cout << ans.size() << endl;
}
