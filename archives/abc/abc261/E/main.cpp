#include <cassert>
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
    ll N, C;
    cin >> N >> C;
    vl T(N), A(N);
    vl ans(N);
    rep(i, N) { cin >> T[i] >> A[i]; }
    for (int k = 0; k < 31; k++) {
        ll xk = (C >> k) & 1;
        assert(xk == 0 || xk == 1);
        array<int, 2> func = {0, 1};
        rep(i, N) {
            ll ti = T[i];
            ll ai = A[i];
            int aik = (ai >> k) & 1;
            assert(aik == 0 || aik == 1);
            array<int, 2> f;
            if (ti == 1) {
                f = {0 & aik, 1 & aik};
            } else if (ti == 2) {
                f = {0 | aik, 1 | aik};
            } else {
                f = {0 ^ aik, 1 ^ aik};
            }
            func = {f[func[0]], f[func[1]]};
            xk = func[xk];
            ans[i] |= (xk << k);
        }
    }

    rep(i, N) { cout << ans[i] << endl; }
}
