#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int A, B;
    cin >> A >> B;
    rep(i, 10) {
        if (A + B != i) {
            cout << i << endl;
            return 0;
        }
    }
}
