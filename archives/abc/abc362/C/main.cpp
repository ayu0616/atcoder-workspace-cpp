#include <cassert>
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
    ll N;
    cin >> N;
    vl L(N), R(N);
    rep(i, N) { cin >> L[i] >> R[i]; }
    vl X(N, 0);
    rep(i, N) X[i] = L[i];
    ll sum = accumulate(all(X), 0LL);
    if (sum > 0) {
        cout << "No" << endl;
        return 0;
    }
    rep(i, N) {
        ll diff = R[i] - L[i];
        ll d = min(-sum, diff);
        X[i] += d;
        sum += d;
    }
    if (sum < 0) {
        cout << "No" << endl;
        return 0;
    }
    assert(accumulate(all(X), 0LL) == 0);
    cout << "Yes" << endl;
    cout << X << endl;
}
