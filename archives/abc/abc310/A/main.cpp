#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;
    vi d(n);
    rep(i, n) cin >> d[i];
    int ans = p;
    rep(i, n)
    {
        ans = min(ans, d[i] + q);
    }
    cout << ans << endl;
}
