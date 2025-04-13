#ifdef ONLINE_JUDGE
#define NDEBUG
#endif
#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

constexpr int MOD = 1000000000;
using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N_ll, K_ll;
    cin >> N_ll >> K_ll;
    int N = N_ll;
    int K = K_ll;
    if (N == 0) {
        cout << 1 << endl;
        return 0;
    }
    vector<mint> dp(N + 1);
    mint current_sum = 0;
    for (int i = 0; i < K; ++i) {
        if (i <= N) {
            dp[i] = 1;
            current_sum += dp[i];
        } else {
            break;
        }
    }
    if (K <= N) {
        dp[K] = current_sum;
    }
    for (int i = K + 1; i <= N; ++i) {
        dp[i] = dp[i - 1] * 2 - dp[i - K - 1];
    }
    cout << dp[N] << endl;
    return 0;
}
