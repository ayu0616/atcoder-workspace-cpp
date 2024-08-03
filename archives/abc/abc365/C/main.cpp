#include <algorithm>
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
    vl A(N);
    cin >> A;
    sort(all(A));
    vl A_sum(N + 1);
    rep(i, N) { A_sum[i + 1] = A_sum[i] + A[i]; }
    ll r = LL_INF, l = 1;
    while (r - l > 1) {
        ll m = (r + l) / 2;
        ll idx = upper_bound(all(A), m) - A.begin();
        ll cnt = (N - idx) * m + A_sum[idx];
        if (cnt > M) {
            r = m;
        } else {
            l = m;
        }
    }
    if (r == LL_INF) {
        cout << "infinite" << endl;
    } else {
        cout << l << endl;
    }
}
