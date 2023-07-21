#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int t, n;
vi p;
vvi a, b; // aはiが抜いた人、bはiを抜いた人

int main()
{
    cin >> t;

    while (t)
    {
        t--;
        cin >> n;
        p = vi(n);
        a = vvi(n), b = vvi(n);
        rep(i, n) cin >> p[i];
        rep(i, n) p[i]--;
        rep(i, n) rep2(j, i + 1, n)
        {
            if (p[i] > p[j])
            {
                a[j].push_back(i);
                b[i].push_back(j);
            }
        }
        int ans = 0;
        rep(i, n) ans += (b[i].size() == 0 ? 1 : 0);
        cout << ans << endl;
    }
}
