#include <iostream>
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
    vl A(N), B(N);
    rep(i, N) { cin >> A[i]>> B[i]; }
    ll ans = accumulate(all(A), 0LL);
    ll tmp = ans;
    rep(i, N) { chmax(ans, tmp - A[i] + B[i]); }
    cout << ans << endl;
}
