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
    int N = min(S.size(), T.size());
    rep(i, N) {
        if (S[i] == T[i]) {
            continue;
        }
        if (S[i] != T[i]) {
            cout << i+1 << endl;
            return 0;
        }
    }
    if(S.size()!=T.size()) {
        cout << N+1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}
