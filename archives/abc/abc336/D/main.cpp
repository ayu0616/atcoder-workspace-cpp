#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    vi left(N), right(N);
    left[0] = 1;
    rep(i, N - 1) {
        if (A[i + 1] > left[i]) {
            left[i + 1] = left[i] + 1;
        } else if (A[i + 1] == left[i]) {
            left[i + 1] = left[i];
        } else {
            left[i + 1] = min(left[i] - 1, A[i + 1]);
        }
    }
    right[N - 1] = 1;
    for (int i = N - 2; i >= 0; i--) {
        if (A[i] > right[i + 1]) {
            right[i] = right[i + 1] + 1;
        } else if (A[i] == right[i + 1]) {
            right[i] = right[i + 1];
        } else {
            right[i] = min(right[i + 1] - 1, A[i]);
        }
    }
    int ans = 0;
    rep(i, N) { chmax(ans, min(left[i], right[i])); }
    cout << ans << endl;
}
