#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    int upper = 200010;
    ll cnt[upper];
    rep(i, upper) cnt[i] = 0;
    rep(i, n) cnt[a[i]]++;
    rep(i, upper) cnt[i + 1] += cnt[i];

    ll ans = 0;
    for (int j = 0; j < n; j++)
    {
        ans += cnt[a[j] - 1] * (n - cnt[a[j]]);
    }

    cout << ans << endl;
}
