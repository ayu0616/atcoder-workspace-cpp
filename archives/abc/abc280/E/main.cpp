#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

map<ll, mint> fact_memo;
mint fact(ll n) {
    if (n == 0) return 1;
    if (fact_memo.count(n)) return fact_memo[n];
    return fact_memo[n] = fact(n - 1) * n;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, P;
    cin >> N >> P;
    mint p = P;
    p /= 100;
    mint q = -p + 1;
    vector<mint> dp(N + 1, 0);
    dp[N] = 0;
    for (ll i = N - 1; i >= 0; --i) {
        dp[i] = (dp[i + 1] * q + dp[min(N, i + 2)] * p) + 1;
    }
    cout << dp[0] << endl;
}
