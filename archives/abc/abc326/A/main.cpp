#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll X, Y;
    cin >> X >> Y;
    ll diff = Y - X;
    if (-3 <= diff && diff <= 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
