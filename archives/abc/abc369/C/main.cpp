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
    ll l = 0, r = 1;
    ll a = A[l], d = A[r] - A[r - 1];
    ll ans = 0;
    while (r < N) {
        if (A[r] - A[r - 1] == d) {
            r++;
        } else {
            ll len = r - l - 2;
            ans += len * (len + 1) / 2;
            l = r - 1;
            a = A[l];
            d = A[r] - A[r - 1];
        }
    }
    ll len = r - l - 2;
    ans += len * (len + 1) / 2;
    ans += N + (N - 1);
    cout << ans << endl;
}
