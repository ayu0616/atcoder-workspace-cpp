#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll B;
    cin >> B;
    ll ans = -1;
    rep(i, 1, 17)
    {
        if (powl(i, i) == B)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
