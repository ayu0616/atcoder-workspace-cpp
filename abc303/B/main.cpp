#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vvi a(m, vi(n));
    rep(i, m) rep(j, n) cin >> a[i][j];
    set<pair<int, int>> s;
    rep(i, n) rep2(j, i + 1, n) s.insert({i + 1, j + 1});

    rep(i, m)
    {
        rep(j, n - 1)
        {
            if (s.find({min(a[i][j], a[i][j + 1]), max(a[i][j], a[i][j + 1])}) != s.end())
            {
                s.erase(s.find({min(a[i][j], a[i][j + 1]), max(a[i][j], a[i][j + 1])}));
            }
        }
    }

    cout << s.size() << endl;
}
