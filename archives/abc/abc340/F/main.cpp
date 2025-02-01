#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

#include "hassaku/gcd.hpp"

using namespace hassaku;

int main() {
    cout << fixed << setprecision(18);
    ll X, Y;
    cin >> X >> Y;
    ll g = gcd(X, Y);
    if (g >= 3) {
        cout << -1 << endl;
        return 0;
    }
    auto [A, B] = extgcd(Y, -X);
    if (g == 1) {
        A *= 2;
        B *= 2;
    }
    assert(abs(A * Y - B * X) == 2);
    cout << A << " " << B << endl;
}
