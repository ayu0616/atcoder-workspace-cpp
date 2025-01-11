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
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    sort(all(A));
    ll ans = 0;
    rep(i, N) {
        ll a = A[i];
        auto it = upper_bound(all(A), a / 2);
        ans += (it - A.begin());
    }
    cout << ans << endl;
}
