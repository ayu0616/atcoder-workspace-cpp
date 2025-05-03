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
    array<int, 7> A;
    rep(i, 7) cin >> A[i];
    sort(all(A));
    for (ll S = 0; S < 1 << 7; S++) {
        vi B;
        rep(i, 7) {
            if (S >> i & 1) B.push_back(A[i]);
        }
        if (B.size() != 5) continue;
        sort(all(B));
        if (B[0] == B[1] && B[1] == B[2] && B[2] != B[3] && B[3] == B[4]) {
            cout << "Yes" << endl;
            return 0;
        }
        if (B[0] == B[1] && B[1] != B[2] && B[2] == B[3] && B[3] == B[4]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
