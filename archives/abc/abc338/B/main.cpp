#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    string S;
    cin >> S;
    map<char, int> m;
    rep(i, S.size()) { m[S[i]]++; }
    char ans;
    int max_cnt = 0;
    for (char c = 'a'; c <= 'z'; c++) {
        if (max_cnt < m[c]) {
            max_cnt = m[c];
            ans = c;
        }
    }
    cout << ans << endl;
}
