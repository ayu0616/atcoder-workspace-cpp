#include <iostream>
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
    vs S(8);
    cin >> S;
    rep(i, 8) rep(j, 8) {
        if (S[i][j] == '#') {
            rep(k, 8) {
                if (S[k][j] != '#') {
                    S[k][j] = 'x';
                }
                if (S[i][k] != '#') {
                    S[i][k] = 'x';
                }
            }
        }
    }
    int ans = 0;
    rep(i, 8) rep(j, 8) {
        if (S[i][j] == '.') {
            ans++;
        }
    }
    cout << ans << endl;
}
