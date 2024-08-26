#include <algorithm>
#include <cassert>
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
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;
    rep(i, N) { A[i] %= M; }
    vl A_sum(2 * N + 1);
    rep(i, 2 * N) { A_sum[i + 1] = (A_sum[i] + A[i % N]) % M; }
    vl cnt(M);
    rep(i, N) { cnt[A_sum[i]]++; }
    ll ans = 0;
    rep(i, N) {
        cnt[A_sum[i]]--;
        ans += cnt[A_sum[i]];
        cnt[A_sum[i + N]]++;
    }
    cout << ans << endl;
}
