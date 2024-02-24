#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string S;
    cin >> S;
    char s0 = S[0];
    int s0_cnt = 0;
    int s_other_idx;
    rep(i, S.length()) {
        char c = S[i];
        if (c == s0) {
            s0_cnt++;
        } else {
            s_other_idx = i;
        }
    }
    if (s0_cnt == 1) {
        cout << 1 << endl;
    } else {
        cout << s_other_idx + 1 << endl;
    }
}
