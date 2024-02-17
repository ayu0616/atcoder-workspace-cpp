#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll X, Y;
    cin >> X >> Y;
    if (X == 0) swap(X, Y);
    ll A, B;
    ll Y_mod = Y%X;
    for (A = 0; A < X; A++) {
        if ((-A * Y_mod + 2) % X == 0) {
            B = (-A * Y + 2) / X;
            break;
        }
        if ((-A * Y_mod - 2) % X == 0) {
            B = (-A * Y - 2) / X;
            break;
        }
    }

    if (X == 0) swap(A, B);
    cout << A << " " << B << endl;
}
