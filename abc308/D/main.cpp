#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

string snuke = "snuke";
string ans = "No";

void solve(int i, int j, int k, vvi &visited, vector<string> &grid)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j] == 1 || grid[i][j] != snuke[k])
    {
        return;
    }
    visited[i][j] = 1;
    if (visited[grid.size() - 1][grid[0].size() - 1] == 1)
    {
        ans = "Yes";
        return;
    }
    solve(i + 1, j, (k + 1) % 5, visited, grid);
    solve(i - 1, j, (k + 1) % 5, visited, grid);
    solve(i, j + 1, (k + 1) % 5, visited, grid);
    solve(i, j - 1, (k + 1) % 5, visited, grid);
    return;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vvi visited(h, vi(w, 0));
    solve(0, 0, 0, visited, s);
    cout<<ans<<endl;
}
