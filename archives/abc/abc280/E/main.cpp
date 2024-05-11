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
    mint p = 100 / P;
    mint ans = 0;
    ll two_cnt = N / 2;
    while (two_cnt >= 0) {
        ll one_cnt = N - two_cnt * 2;
        ll n = one_cnt + two_cnt;
        ans += fact(n) / (fact(two_cnt) * fact(one_cnt)) * p.pow(two_cnt) * ((mint)1 - p).pow(one_cnt) * n;
        two_cnt--;
    }
    cout << ans << endl;
}
