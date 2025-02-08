#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr ll e18 = 1000000000000000000;

int main() {
    cout << fixed << setprecision(18);
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    ll a = ((A) % M + M) % M;
    L -= a;
    R -= a;
    ll l = L;
    if (l < 0) {
        l -= l % M;
    } else {
        l += (M - l % M) % M;
    }
    ll r = R;
    if (r < 0) {
        r -= (r % M + M) % M;
    } else {
        r -= r % M;
    }
    if (l > r) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = r / M - l / M + 1;
    cout << ans << endl;
}
