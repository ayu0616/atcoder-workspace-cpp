#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    vl A_sum(N + 1, 0);
    rep(i, 0, N) { A_sum[i + 1] = A_sum[i] + A[i]; }
    mint ans = 0;
    rep(i, N) {
        ll a = A[i];
        int digit = 0;
        ll tmp = a;
        while (tmp > 0) {
            tmp /= 10;
            digit++;
        }
        mint ten = ((mint)10).pow(digit);
        ans += ten * A_sum[i] + a * i;
    }
    cout << ans << endl;
}
