#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int calc_lcm(vl a) {
    int res = a[0];
    for (int i = 1; i < a.size(); i++) {
        res = lcm(res, a[i]);
    }
    return res;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, X, Y;
    cin >> N >> X >> Y;
    vl P(N - 1), T(N - 1);
    rep(i, N - 1) { cin >> P[i] >> T[i]; }
    const int K = calc_lcm(P);
    vector t(K, 0LL);
    rep(k, K) {
        ll cur = k;
        cur += X;
        rep(i, N - 1) {
            ll p = P[i];
            ll t = T[i];
            if (cur % p == 0) {
                cur += t;
            } else {
                cur += p - (cur % p);
                cur += t;
            }
        }
        cur += Y;
        t[k] = cur - k;
    }
    ll Q;
    cin >> Q;
    while (Q--) {
        ll q;
        cin >> q;
        cout << q + t[q % K] << endl;
    }
}
