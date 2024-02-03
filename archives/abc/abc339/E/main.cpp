#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, D;
    cin >> N >> D;
    vi A(N);
    cin >> A;
    vi dp(N, 0);
    SegTree seg(5 * 1e5 + 10);
    seg.update(0, 5 * 1e5 + 10, 0);
    rep(i, N) {
        int a = A[i];
        int m = -seg.query(max(0, a - D), min(5 * 1e5 + 10, a + D + 1));
        dp[i] = m + 1;
        seg.update(a, a + 1, -dp[i]);
    }
    cout << max(dp) << endl;
}
