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
    ll K;
    string S, T;
    cin >> K >> S >> T;

    if (S == T) {
        cout << "Yes" << endl;
        return 0;
    }
    if (S.size() == T.size()) {
        int not_eq_idx = -1;
        rep(i, S.size()) {
            if (S[i] != T[i]) {
                if (not_eq_idx != -1) {
                    cout << "No" << endl;
                    return 0;
                }
                not_eq_idx = i;
            }
        }
        if (not_eq_idx == -1) {
            cout << "No" << endl;
            return 0;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            string s = S;
            s[not_eq_idx] = c;
            if (s == T) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    if (S.size() == T.size() + 1) {
        swap(S, T);
    }
    if (S.size() + 1 == T.size()) {
        int not_eq_idx = -1;
        rep(i, S.size()) {
            if (S[i] != T[i]) {
                not_eq_idx = i;
                break;
            }
        }
        if (not_eq_idx == -1) {
            cout << "Yes" << endl;
            return 0;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            string s = S;
            s.insert(not_eq_idx, 1, c);
            if (s == T) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}
