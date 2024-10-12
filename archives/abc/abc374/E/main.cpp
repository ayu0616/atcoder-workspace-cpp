#include <algorithm>
#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll div_ceil(ll a, ll b) { return (a + b - 1) / b; }

ll min_c(ll W, ll A, ll P, ll B, ll Q) {
    ll mc = LL_INF;
    rep(a, A + 1) {
        ll b = max(0LL, div_ceil(W - a * A, B));
        mc = min(mc, a * P + b * Q);
    }
    rep(b, B + 1) {
        ll a = max(0LL, div_ceil(W - b * A, B));
        mc = min(mc, a * P + b * Q);
    }
    return mc;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, X;
    cin >> N >> X;
    vl A(N), P(N), B(N), Q(N);
    rep(i, N) { cin >> A[i] >> P[i] >> B[i] >> Q[i]; }

    ll l = 0;
    ll r = 1e18;

    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll c = 0;
        rep(i, N) { c += min_c(m, A[i], P[i], B[i], Q[i]); }
        if (c <= X) {
            l = m;
        } else {
            r = m;
        }
    }
    if (l > 1e16) {
        cout << 0 << endl;
        return 0;
    }
    cout << l << endl;
}
