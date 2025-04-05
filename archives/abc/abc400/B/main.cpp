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
    ll N, M;
    cin >> N >> M;
    ll ans = 0;
    rep(i, M + 1) {
        ans += pow(N, i);
        if (ans > 1e9) {
            cout << "inf" << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
