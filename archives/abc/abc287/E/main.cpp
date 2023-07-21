#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

vector<int> ans, siz;
vector<string> s;

void solve(vector<vector<int>> &m, int k)
{
    for (int key = 0; key < 26; key++)
    {
        if (m[key].size() == 0)
            continue;
        if (m[key].size() == 1)
        {
            ans[*m[key].begin()] = k - 1;
            continue;
        }
        vector<vector<int>> m2(26, vector<int>());
        for (int i : m[key])
        {
            if (siz[i] == k)
            {
                ans[i] = k;
                continue;
            }
            m2[s[i][k] - 'a'].emplace_back(i);
        }
        solve(m2, k + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    s = vector<string>(n);
    siz = vector<int>(n);
    vector<vector<int>> m(26, vector<int>());
    for (int i = 0; i < n; i++)
    {
        string si;
        cin >> si;
        s[i] = si;
        siz[i] = si.size();
        m[si[0] - 'a'].emplace_back(i);
    }

    ans = vector<int>(n, 0);
    solve(m, 1);
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}
