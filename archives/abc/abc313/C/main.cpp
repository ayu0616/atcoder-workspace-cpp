#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    ll mean = 0;
    rep(i, n) mean += a[i];
    mean /= n;
    ll sm=0, lg = 0;
    rep(i, n)
    {
        if (a[i] == mean || a[i] == mean + 1)
            continue;
        if (a[i] < mean)
            sm += mean - a[i];
        else
            lg += a[i] - mean - 1;
    }
    cout << max(sm, lg) << endl;
}
