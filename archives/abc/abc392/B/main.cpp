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
    ll N, M;
    cin >> N >> M;
    vl A(M);
    cin >> A;
    vb ok(N + 10);
    rep(i, M) { ok[A[i]] = true; }
    vl ans;
    rep(i, 1, N + 1) {
        if (ok[i]) continue;
        ans.push_back(i);
    }
    cout << ans.size() << endl;
    if (ans.size() == 0) return 0;
    cout << ans << endl;
}
