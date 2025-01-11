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
    ll N, D;
    cin >> N >> D;
    vl T(N), L(N);
    rep(i, N) cin >> T[i] >> L[i];
    for (int k = 1; k <= D; k++) {
        ll ans = 0;
        rep(i, N) { chmax(ans, T[i] * (L[i] + k)); }
        cout << ans << endl;
    }
}
