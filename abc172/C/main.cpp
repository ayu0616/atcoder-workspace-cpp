#include "../../lib.hpp"

ll n, m, k;
vector<ll> a, b;

int main()
{
    cin >> n >> m >> k;
    vector_in(a, n);
    vector_in(b, m);
    ll a_sum[n + 1], b_sum[m + 1];
    a_sum[0] = 0;
    b_sum[0] = 0;
    rep(i, n) a_sum[i + 1] = a_sum[i] + a[i];
    rep(i, m) b_sum[i + 1] = b_sum[i] + b[i];

    ll ans = 0;
    ll ok = m;
    rep(i, n + 1)
    {
        if (a_sum[i] > k)
            break;
        while (ok >= 0 && b_sum[ok] + a_sum[i] > k)
            ok--;
        if (ok >= 0)
            ans = max(ans, i + ok);
    }

    cout << ans << endl;
}
