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
    string S;
    cin >> S;
    int l = -1, cnt = 0;
    rep(i, S.size()) {
        if (l == -1) {
            if (S[i] == 'W') {
                l = i;
            }
        } else {
            if (S[i] == 'W') {
            } else if (S[i] == 'A') {
                S[l] = 'A';
                for (int j = l + 1; j <= i; j++) {
                    S[j] = 'C';
                }
                l = -1;
            } else {
                l = -1;
            }
        }
    }
    cout << S << endl;
}
