#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
map<ll, ll> memo;
ll f(ll n) {
    if (n == 1) return 1;
    if (memo.count(n)) return memo[n];
    ll half = n / 2;
    return memo[n] = n + f(half) + f(half + n % 2);
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    cout << f(N) - N << endl;
}
