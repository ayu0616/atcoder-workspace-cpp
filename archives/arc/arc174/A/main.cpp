#include <numeric>
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
    ll N, C;
    cin >> N >> C;
    vl A(N);
    cin >> A;
    ll ans = accumulate(all(A), 0LL);

    vl dp_internal(N + 1, 0);
    vl dp_suffix(N + 1, 0);
    ll sign = C > 0 ? 1 : -1;
    rep(i, N) {
        dp_internal[i + 1] = max(dp_internal[i], dp_suffix[i] + A[i] * sign);
        dp_suffix[i + 1] = max(A[i] * sign, dp_suffix[i] + A[i] * sign);
    }

    cout << ans + (dp_internal[N] > 0 ? sign * dp_internal[N] * (C - 1) : 0) << endl;
}
