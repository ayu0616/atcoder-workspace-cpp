#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vl a(n);
    rep(i, n) cin >> a[i];
    vl b(n - 2);
    ll ans1 = 0;
    while (a[0] > a[1])
    {
        a[0]--;
        ans1++;
    }
    rep(i, n - 2)
    {
        if (a[0] > a[i + 2])
        {
            b[i] = a[i + 2] - a[0];
        }
        else if (a[1] < a[i + 2])
        {
            b[i] = a[i + 2] - a[1];
        }
        else
        {
            b[i] = 0;
        }
    }
    sort(b.begin(), b.end());
    ll mi = 1e18;
    rep(i, n - 1 - m)
    {
        ll tmp_m = 0, tmp_p = 0;
        rep(j, m)
        {
            if (b[i + j] < 0)
                tmp_m = max(-b[i + j], tmp_m);
            else
                tmp_p = max(b[i + j], tmp_p);
        }
        mi = min(mi, tmp_m + tmp_p);
    }
    ans1 += mi;

    ll ans2 = 0;
    while (a[0] > a[1])
    {
        a[1]++;
        ans2++;
    }
    rep(i, n - 2)
    {
        if (a[0] > a[i + 2])
        {
            b[i] = a[i + 2] - a[0];
        }
        else if (a[1] < a[i + 2])
        {
            b[i] = a[i + 2] - a[1];
        }
        else
        {
            b[i] = 0;
        }
    }
    sort(b.begin(), b.end());
    mi = 1e18;
    rep(i, n - 1 - m)
    {
        ll tmp_m = 0, tmp_p = 0;
        rep(j, m)
        {
            if (b[i + j] < 0)
                tmp_m = max(-b[i + j], tmp_m);
            else
                tmp_p = max(b[i + j], tmp_p);
        }
        mi = min(mi, tmp_m + tmp_p);
    }
    ans2 += mi;
    cout << min(ans1, ans2) << endl;
}
