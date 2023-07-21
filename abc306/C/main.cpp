#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(3 * n);
    rep(i, 3 * n) cin >> a[i];

    vi p(n + 1, -1);
    rep(i, 3 * n)
    {
        if (p[a[i]] == -1)
        {
            p[a[i]] = 0;
        }
        else if (p[a[i]] == 0)
        {
            p[a[i]] = i + 1;
        }
    }

    vpii b(n);
    rep(i, n)
    {
        b[i] = {p[i + 1], i + 1};
    }
    sort(all(b));

    vi ans(n);
    rep(i, n)
    {
        ans[i] = b[i].second;
    }

    cout << ans << endl;
}
