#include <iostream>
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
    ll N, K, X;
    cin >> N >> K >> X;
    vl A(N);
    cin >> A;
    rep(i, K) cout << A[i] << " ";
    cout << X;
    rep(i, K, N) cout << " " << A[i];
    cout << endl;
}
