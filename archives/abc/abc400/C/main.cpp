#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    ll ans = 0;
    for (int a = 1; (1ll << a) <= N; a++) {
        ll b_sq = N >> a;
        ll b = sqrt(b_sq);
        b = max(b - 10, 0);
        while ((b + 1) * (b + 1) * (1LL << a) <= N) b++;
        ans += (b + 1) / 2;
        // debug(a);
        // debug((b + 1) / 2);
    }
    cout << ans << endl;
}
