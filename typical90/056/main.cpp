#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, S;
    cin >> N >> S;
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];
    vvi dp(N + 1, vi(S + 1, 0));
    vs prev_choices(S + 1), cur_choices(S + 1);
    dp[0][0] = 1;
    rep(i, N) {
        rep(s, S) {
            if (s + A[i] <= S) {
                if (dp[i + 1][s + A[i]]) continue;
                dp[i + 1][s + A[i]] |= dp[i][s];
                if (dp[i + 1][s + A[i]]) {
                    cur_choices[s + A[i]] = prev_choices[s] + "A";
                }
            }
            if (s + B[i] <= S) {
                if (dp[i + 1][s + B[i]]) continue;
                dp[i + 1][s + B[i]] |= dp[i][s];
                if (dp[i + 1][s + B[i]]) {
                    cur_choices[s + B[i]] = prev_choices[s] + "B";
                }
            }
        }
        prev_choices = cur_choices;
        cur_choices = vs(S + 1);
    }
    if (dp[N][S]) {
        cout << prev_choices[S] << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
