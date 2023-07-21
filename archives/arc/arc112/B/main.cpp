#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll b, c;
    cin >> b >> c;

    ll plus_l = b - c / 2;
    ll plus_r = -(-b - (c - 2) / 2);
    ll minus_l = -b - (c - 1) / 2;
    ll minus_r = -(b - (c - 1) / 2);

    // plus_l += plus_l < 0;
    // plus_r += plus_r < 0;
    // minus_l += minus_l < 0;
    // minus_r += minus_r < 0;

    ll ans = 0;

    if (minus_r >= plus_l)
    {
        ans = max(plus_r, minus_r) - min(plus_l, minus_l) + 1;
    }
    else
    {
        ans = plus_r - plus_l + 1 + minus_r - minus_l + 1;
    }

    cout << ans << endl;
}
