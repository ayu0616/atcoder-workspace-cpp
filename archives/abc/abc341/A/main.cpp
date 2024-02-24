#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N;
    cin >> N;
    rep(i, 2 * N + 1) {
        if (i % 2 == 0)
            cout << '1';
        else
            cout << '0';
    }
    cout << endl;
}
