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

ll min_c(ll w, ll a, ll p, ll b, ll q) {
    ll low = 0;
    ll high = (w + b - 1) / b;
    while (high - low > 3) {
        ll m1 = low + (high - low) / 3;
        ll m2 = high - (high - low) / 3;
        ll c1 = m1 * q + ((max(w - m1 * b, 0LL) + a - 1) / a) * p;
        ll c2 = m2 * q + ((max(w - m2 * b, 0LL) + a - 1) / a) * p;
        if (c1 < c2) {
            high = m2;
        } else {
            low = m1;
        }
    }
    ll mc = LL_INF;
    for (ll bb = low; bb <= high; bb++) {
        ll req = max(0LL, (w - bb * b));
        ll aa = (req + a - 1) / a;
        mc = min(mc, bb * q + aa * p);
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
