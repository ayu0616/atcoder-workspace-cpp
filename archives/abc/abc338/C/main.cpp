#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vi Q(N), A(N), B(N);
    cin >> Q >> A >> B;
    int a_min = 1e9, b_min = 1e9;
    rep(i, N) {
        if (A[i] > 0) {
            chmin(a_min, Q[i] / A[i]);
        }
        if (B[i] > 0) {
            chmin(b_min, Q[i] / B[i]);
        }
    }
    if (a_min > b_min) {
        swap(a_min, b_min);
        swap(A, B);
    }
    int ans = 0;
    rep(i, a_min + 1) {
        b_min = 1e9;
        rep(j, N) {
            if (B[j] > 0) {
                chmin(b_min, (Q[j] - (int)i * A[j]) / B[j]);
            }
        }
        chmax(ans, (int)i + b_min);
    }
    cout << ans << endl;
}
