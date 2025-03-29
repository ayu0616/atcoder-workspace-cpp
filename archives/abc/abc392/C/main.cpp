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

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vi P(N), Q(N);
    cin >> P >> Q;
    rep(i, N) {
        P[i]--;
        Q[i]--;
    }
    vi ans(N, -1);
    rep(i, N) {
        int p = P[i];
        int q = Q[i];
        ans[q] = Q[p] + 1;
    }
    cout << ans << endl;
}
