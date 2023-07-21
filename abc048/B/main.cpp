#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans;
    if (a == 0)
    {
        ans = b / x + 1;
    }
    else
    {
        ll b_x = b / x;
        ll a_x = (a - 1) / x;
        ans = b_x - a_x;
    }
    cout << ans << endl;
}
