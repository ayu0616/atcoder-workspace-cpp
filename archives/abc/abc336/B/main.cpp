#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    rep(i, log2(N) + 1) {
        if (N >> i & 1) {
            cout << i << endl;
            break;
        }
    }
}
