#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vi p(n), c(n);
    vvi f(n, vi(m, 0));
    rep(i, n)
    {
        cin >> p[i] >> c[i];
        rep(j, c[i])
        {
            int tmp;
            cin >> tmp;
            f[i][tmp - 1] = 1;
        }
    }
    string ans = "No";
    rep(i, n) rep(j, n)
    {
        if (i == j)
            continue;
        if (p[i] < p[j])
            continue;
        bool ok = true, is_up = false;
        rep(k, m)
        {
            if (f[i][k] && !f[j][k])
            {
                ok = false;
                break;
            }
            else if (!f[i][k] && f[j][k])
            {
                is_up = true;
            }
        }
        if (!ok)
            continue;
        if (p[i] > p[j] || is_up)
            ans = "Yes";
    }
    cout << ans << endl;
}
