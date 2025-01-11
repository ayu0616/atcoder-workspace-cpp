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
    vl B(N + 1);
    vl ans(N);
    ll cur = 0;
    rep(i, N) {
        ll a = A[i];
        cur += B[i];
        a += cur;
        B[i + 1]++;
        B[min(N, i + a + 1)]--;
        ans[i] = a - (min(N-1, i + a) - i) ;
    }
    cout << ans << endl;
}
