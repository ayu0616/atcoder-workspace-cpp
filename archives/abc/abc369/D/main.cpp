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
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    ll dp[N + 1][2];
    rep(i, N + 1) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    rep(i, N) {
        dp[i + 1][1] = max(dp[i][0] + A[i], dp[i][1]);
        if (i != 0) {
            dp[i + 1][0] = max(dp[i ][1] + A[i] * 2, dp[i][0]);
        }
    }
    cout << max(dp[N][0], dp[N][1]) << endl;
}
