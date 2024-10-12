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
    ll N;
    cin >> N;
    vl X(N), Y(N);
    rep(i, N) { cin >> X[i] >> Y[i]; }
    double ans = 0;
    ll x = 0, y = 0;
    rep(i, N) {
        ans += sqrt((X[i] - x) * (X[i] - x) + (Y[i] - y) * (Y[i] - y));
        x = X[i];
        y = Y[i];
    }
    ans += sqrt(x * x + y * y);
    cout << ans << endl;
}
