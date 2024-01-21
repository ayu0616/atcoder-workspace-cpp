#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    string S;
    cin >> S;
    int cur = 0;
    while (S.size() && S[0] == 'A') {
        S = S.substr(1);
    }
    while (S.size() && S[0] == 'B') {
        S = S.substr(1);
    }
    while (S.size() && S[0] == 'C') {
        S = S.substr(1);
    }
    yes_no(S.size() == 0);
}
