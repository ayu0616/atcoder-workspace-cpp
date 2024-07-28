#include <algorithm>
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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vl A(N), B(N);
    cin >> A >> B;
    sort(all(A));
    sort(all(B));
    reverse(all(A));
    reverse(all(B));
    vl A_sum(N + 1, 0), B_sum(N + 1, 0);
    rep(i, N) {
        A_sum[i + 1] = A_sum[i] + A[i];
        B_sum[i + 1] = B_sum[i] + B[i];
    }
    int a_i = lower_bound(all(A_sum), X) - A_sum.begin();
    int b_i = lower_bound(all(B_sum), Y) - B_sum.begin();
    if (A_sum[a_i] == X) a_i++;
    if (B_sum[b_i] == Y) b_i++;
    if (a_i == N + 1 && b_i == N + 1) {
        cout << N << endl;
        return 0;
    }
    cout << min(a_i, b_i) << endl;
}
