#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

map<int, mint> fact;
mint factorial(ll n) {
    if (fact.count(n)) return fact[n];
    if (n == 0) return 1;
    if (n == 1) return fact[n] = 1;
    return fact[n] = factorial(n - 1) * n;
}

mint combination(ll n, ll k) {
    if (k < 0 || k > n) return 0;
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main() {
    cout << fixed << setprecision(18);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    mint ans = 0;
    rep(n, B + 1) {
        rep(m, C + 1) { ans += combination(A + n, n) * combination(B - n + m, m) * combination(C - m + D, D); }
    }
    cout << ans << endl;
    return 0;
}
