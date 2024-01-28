#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vl x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    vl x1(N), y1(N);
    rep(i, N) {
        x1[i] = x[i] + y[i];
        y1[i] = x[i] - y[i];
    }
    ll x_min = min(x1), x_max = max(x1);
    ll y_min = min(y1), y_max = max(y1);
    while (Q--) {
        int q;
        cin >> q;
        q--;
        ll cx = x1[q], cy = y1[q];
        ll ans = max(abs(cx - x_min), abs(cx - x_max), abs(cy - y_min), abs(cy - y_max));
        cout << ans << endl;
    }
}
