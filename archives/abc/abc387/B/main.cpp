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
    ll ans = 0;
    rep(i, 1, 10) rep(j, 1, 10) {
        if (i * j == N) continue;
        ans += i * j;
    }
    cout << ans << endl;
}
