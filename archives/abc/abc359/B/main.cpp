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
    vi A(2 * N);
    cin >> A;
    int p = A[0];
    int ans = 0;
    rep(i, 2, 2 * N) {
        if (A[i] == p) {
            ans++;
        }
        p = A[i - 1];
    }
    cout << ans << endl;
}
