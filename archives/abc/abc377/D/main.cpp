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
    vl L(N), R(N);
    rep(i, N) cin >> L[i] >> R[i];
    vpll lr(N);
    rep(i, N) lr[i] = {L[i], R[i]};
    vl min_r(M + 1, M + 1);
    sort(all(lr));
    rep(i, N) { min_r[L[i]] = min(min_r[L[i]], R[i]); }
    for(int i = M; i >= 1; i--) { min_r[i-1] = min(min_r[i-1], min_r[i]); }
    ll ans = 0;
    rep(i, 1, M + 1) { ans += max(0, min_r[i] - i); }
    cout << ans << endl;
}
