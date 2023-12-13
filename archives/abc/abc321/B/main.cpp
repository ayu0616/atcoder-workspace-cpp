#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, X;
    cin >> N >> X;
    vl a(N - 1);
    rep(i, N - 1) cin >> a[i];
    ll mi = *min_element(all(a)), ma = *max_element(all(a));
    ll score = accumulate(all(a), 0LL) - mi - ma;
    ll resi = X - score;
    ll ans;
    if (resi <= mi)
        ans = 0;
    else if (resi <= ma)
        ans = resi;
    else
        ans = -1;
    cout << ans << endl;
}
