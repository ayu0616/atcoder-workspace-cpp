#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    string S;
    cin >> S;
    int dot_idx = 0;
    rep(i, S.size()) {
        if (S[i] == '.') {
            dot_idx = i;
        }
    }
    cout << S.substr(dot_idx + 1) << endl;
}
