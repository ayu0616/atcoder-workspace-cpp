#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string T, U;
    cin >> T >> U;
    rep(i, T.size() - U.size() + 1) {
        bool ok = true;
        rep(j, U.size()) {
            if (T[i + j] == '?') {
                continue;
            }
            if (T[i + j] != U[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
