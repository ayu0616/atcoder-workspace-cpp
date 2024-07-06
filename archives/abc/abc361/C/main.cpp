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
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    sort(all(A));
    if (N - K == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = LL_INF;
    rep(i, K + 1) { chmin(ans, A[N - K - 1 + i] - A[i]); }
    cout << ans << endl;
}
