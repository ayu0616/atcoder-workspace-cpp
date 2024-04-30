#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string S;
    cin >> S;
    int N = S.size();
    vector<vector<mint>> dp(N + 1, vector<mint>(N + 1, 0));
    dp[0][0] = 1;
    rep(i, N) {
        if (S[i] == '(') {
            rep(j, N) { dp[i + 1][j + 1] += dp[i][j]; }
        } else if (S[i] == ')') {
            rep(j, N) {
                if (j > 0) {
                    dp[i + 1][j - 1] += dp[i][j];
                }
            }
        } else {
            rep(j, N) {
                dp[i + 1][j + 1] += dp[i][j];
                if (j > 0) {
                    dp[i + 1][j - 1] += dp[i][j];
                }
            }
        }
    }
    cout << dp[N][0] << endl;
}
