#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N, S;
    cin >> N >> S;
    vl A(N);
    cin >> A;
    vl A_sum(N + 1, 0);
    rep(i, N) A_sum[i + 1] = A_sum[i] + A[i];
    vl f(N + 1, 0);
    rep(i, N) {
        ll cur = *lower_bound(A_sum.begin(), A_sum.begin() + (i + 1), S);
        f[i + 1]++;
        while (cur != A_sum[i + 1]) {
            cur = *lower_bound(A_sum.begin(), A_sum.begin() + (i + 1), cur + S);
            f[i + 1]++;
        }
    }
    ll ans = 0;
    ll j = N;
    for (int i = N; i >= 1; i--) {
        ans += f[i + 1] * N;
        N -= 2;
    }
    cout << ans << endl;
}
