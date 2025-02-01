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
    ll N, Q;
    cin >> N >> Q;
    int ans = 0;
    vi h(N), cnt(N, 1);
    iota(all(h), 0);
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int P, H;
            cin >> P >> H;
            P--, H--;
            int cur_h = h[P];
            cnt[cur_h]--;
            if (cnt[cur_h] == 1) ans--;
            h[P] = H;
            cnt[H]++;
            if (cnt[H] == 2) ans++;
        } else {
            cout << ans << endl;
        }
    }
}
