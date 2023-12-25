#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vl R(N);
    cin >> R;
    sort(all(R));
    vl R_sum(N + 1, 0);
    rep(i, N) R_sum[i + 1] = R_sum[i] + R[i];
    while (Q--) {
        ll X;
        cin >> X;
        int it = lower_bound(all(R_sum), X) - R_sum.begin();
        it -= (R_sum[it] != X);
        cout << it << endl;
    }
}
