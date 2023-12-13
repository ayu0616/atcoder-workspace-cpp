#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll D;
    cin >> D;
    ll x, y;
    ll ans = 1e18;
    for (y = 0; y <= sqrt(D); y++)
    {
        x = sqrt(D - y * y);
        chmin(ans, abs(x * x + y * y - D));
        x++;
        chmin(ans, abs(x * x + y * y - D));
        x -= 2;
        chmin(ans, abs(x * x + y * y - D));
    }
    cout << ans << endl;
}
