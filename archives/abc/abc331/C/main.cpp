#include <algorithm>
#include <iostream>

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
    auto A_sorted = A;
    sort(all(A_sorted));
    vl A_sum(N + 1, 0);
    rep(i, N) { A_sum[i + 1] = A_sum[i] + A_sorted[i]; }
    vl B(N);
    rep(i, N) {
        auto it = upper_bound(all(A_sorted), A[i]);
        int j = distance(A_sorted.begin(), it);
        B[i] = A_sum.back() - A_sum[j];
    }
    cout << B << endl;
}
