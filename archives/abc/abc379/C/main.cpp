#include <numeric>
#include <ostream>
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
    vl X(M), A(M);
    cin >> X >> A;
    // rep(i, M) X[i]--;

    vpll xa(M);
    rep(i, M) xa[i] = {X[i], A[i]};
    sort(all(xa));
    rep(i, M) {
        auto [x, a] = xa[i];
        X[i] = x;
        A[i] = a;
    }

    ll sum = 0;
    rep(i, M) {
        if (sum < X[i] - 1) {
            cout << -1 << endl;
            return 0;
        }
        sum += A[i];
    }

    if (sum != N) {
        cout << -1 << endl;
        return 0;
    }

    ll xa_sum = 0;
    rep(i, M) { xa_sum += (X[i]) * A[i]; }
    ll ans = N * (N + 1) / 2 - xa_sum;
    cout << ans << endl;
}
