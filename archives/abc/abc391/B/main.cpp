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
    vs S(N), T(M);
    cin >> S >> T;
    rep(a, N - M + 1) rep(b, N - M + 1) {
        bool ok = true;
        rep(i, M) rep(j, M) {
            if (S[a + i][b + j] != T[i][j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << a + 1 << " " << b + 1 << endl;
            return 0;
        }
    }
}
