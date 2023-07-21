#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll a, b;
    cin >> a >> b;
    ll ans = a / b + (a % b != 0);
    cout << ans << endl;
}
