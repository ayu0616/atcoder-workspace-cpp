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
    rep(i, n) cin >> s[i];
    vector<pii> ans;
    rep(i, n - 8) rep(j, m - 8)
    {
        bool ok = true;
        rep(k, 9) rep(l, 9)
        {
            char c = s[i + k][j + l];
            if ((k < 3 && l < 3) || (k > 5 && l > 5))
            {
                if (c == '.')
                {
                    // debug(c);
                    // debug(k);
                    // debug(l);
                    ok = false;
                }
            }
            else if ((k == 3 && l <= 3) || (l == 3 && k <= 3) || (k == 5 && l >= 5) || (l == 5 && k >= 5))
            {
                if (c == '#')
                {
                    // debug(c);
                    // debug(k);
                    // debug(l);
                    ok = false;
                }
            }
        }
        if (ok)
        {
            ans.push_back({i + 1, j + 1});
        }
    }
    sort(all(ans));
    rep(i, ans.size()) cout << ans[i].first << " " << ans[i].second << endl;
}
