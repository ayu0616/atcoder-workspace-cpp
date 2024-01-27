#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    string S;
    cin >> S;
    if (!('A' <= S[0] && S[0] <= 'Z')) {
        cout << "No" << endl;
        return 0;
    }
    for (int i = 1; i < S.size(); i++) {
        if (!('a' <= S[i] && S[i] <= 'z')) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
