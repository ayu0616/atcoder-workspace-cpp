#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    vector<char> a(64);
    rep(i, 64) cin >> a[i];
    // reverse(all(a));

    bitset<64> b;
    rep(i, 64) b.set(i, a[i] == '1' ? true : false);

    cout << b.to_ulong() << endl;
    // ll ans = 0;
    // rep(i, 64)
    // {
    //     ans += a[i] * powl(2, i);
    // }
    // cout << ans << endl;
}
