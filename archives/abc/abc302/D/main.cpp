#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    ll d;
    cin >> n >> m >> d;
    vl a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];
    set<ll, greater<ll>> as, bs;
    rep(i, n) as.insert(a[i]);
    rep(i, m) bs.insert(b[i]);

    ll ans = -1;
    rep(i, n)
    {
        ll b_candidate = *bs.lower_bound(a[i] + d);
        if (abs(b_candidate - a[i]) <= d)
        {
            ans = max(ans, b_candidate + a[i]);
        }
    }

    cout << ans << endl;
}
