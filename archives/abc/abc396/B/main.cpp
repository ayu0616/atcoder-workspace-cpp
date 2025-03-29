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
    ll Q;
    cin >> Q;
    vi stack(100, 0);
    rep(Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            stack.push_back(x);
        } else {
            int x = stack.back();
            stack.pop_back();
            cout << x << endl;
        }
    }
}
