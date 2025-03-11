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
    vl B(N), W(M);
    cin >> B >> W;
    sort(all(B));
    reverse(all(B));
    sort(all(W));
    reverse(all(W));
    vl w_acc(M + 1);
    rep(i, M) w_acc[i + 1] = w_acc[i] + W[i];
    rep(i, M) { chmax(w_acc[i + 1], w_acc[i]); }
    ll ans = 0, cur = 0;
    rep(i, N) {
        cur += B[i];
        chmax(ans, cur + w_acc[min(M, i + 1)]);
    }
    cout << ans << endl;
}
