#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string S, T;
    cin >> S >> T;
    rep(i, S.size()) { S[i] = S[i] - 'a' + 'A'; }
    int idx = 0;
    rep(i, S.size()) {
        if (S[i] == T[idx]) {
            idx++;
        }
        if (idx == 3 || (idx==2&&T[2]=='X')) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
