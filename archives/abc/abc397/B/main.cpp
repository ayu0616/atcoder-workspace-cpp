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
    int N = S.size();
    int ans = 0;
    rep(i, N) {
        int cnt = i + ans + 1;
        if (cnt % 2 == 1 && S[i] == 'o') {
            ans++;
        } else if (cnt % 2 == 0 && S[i] == 'i') {
            ans++;
        }
    }
    if (S.back() == 'i') {
        ans++;
    }
    cout << ans << endl;
}
