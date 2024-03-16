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
    string S;
    cin >> S;
    if (S[0] != '<') {
        cout << "No" << endl;
        return 0;
    }
    if (S[S.size() - 1] != '>') {
        cout << "No" << endl;
        return 0;
    }
    rep(i, 1, S.size() - 1) {
        if (S[i] == '<' || S[i] == '>') {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
