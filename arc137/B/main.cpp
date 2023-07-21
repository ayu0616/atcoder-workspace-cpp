#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) b[i] = a[i] == 1 ? -1 : 1;
    vi s(n + 1);
    s[0] = 0;
    rep(i, n) s[i + 1] = s[i] + b[i];
    int x_min = s[0], sl_max = s[0];
    rep(i, n)
    {
        sl_max = max(sl_max, s[i + 1]);
        x_min = min(x_min, s[i + 1] - sl_max);
    }

    int x_max = s[0], sl_min = s[0];
    rep(i, n)
    {
        sl_min = min(sl_min, s[i + 1]);
        x_max = max(x_max, s[i + 1] - sl_min);
    }
    cout << x_max - x_min + 1 << endl;
}
