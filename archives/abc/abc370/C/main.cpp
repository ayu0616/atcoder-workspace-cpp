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
    vs X;
    rep(i, S.size()) {
        if (S[i] > T[i]) {
            S[i] = T[i];
            X.push_back(S);
        }
    }
    rep(i, S.size()) {
        int j = S.size() - 1 - i;
        if (S[j] != T[j]) {
            S[j] = T[j];
            X.push_back(S);
        }
    }
    cout << X.size() << endl;
    rep(i, X.size()) { cout << X[i] << endl; }
}
