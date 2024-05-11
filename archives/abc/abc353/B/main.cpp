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
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    ll ans = 0, cnt = 0;
    while (cnt < N) {
        ll sum = 0;
        ll i = cnt;
        while (i < N && sum + A[i] <= K) {
            sum += A[i];
            i++;
        }
        ans++;
        cnt = i;
    }
    cout << ans << endl;
}
