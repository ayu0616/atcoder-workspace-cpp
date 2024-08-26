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
    vl X(N), A(N);
    cin >> X >> A;
    vvi to(N, vi(60));
    rep(i, N) { to[i][0] = X[i] - 1; }
    rep(l, 59) {
        rep(i, N) { to[i][l + 1] = to[to[i][l]][l]; }
    }
    vl ans(N);
    rep(i, N) {
        ll now = i;
        rep(l, 60) {
            if (K & (1LL << l)) {
                now = to[now][l];
            }
        }
        ans[i] = A[now];
    }
    cout << ans << endl;
}
