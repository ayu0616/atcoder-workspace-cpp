#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    ll ans = 1;
    for (int i = 0; i < N; i++) {
        if (powl(10, K) / A[i] <= ans) {
            ans = 1;
        } else {
            ans *= A[i];
        }
    }
    cout << ans << endl;
}
