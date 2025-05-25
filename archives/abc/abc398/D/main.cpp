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
    ll N, R, C;
    string S;
    cin >> N >> R >> C >> S;
    ll dx = 0, dy = 0;
    set<pll> st;
    st.insert({0, 0});
    string ans = "";
    rep(i, N) {
        char c = S[i];
        if (c == 'N') dy++;
        if (c == 'S') dy--;
        if (c == 'E') dx--;
        if (c == 'W') dx++;
        st.insert({dy, dx});
        if (st.count({R + dy, C + dx})) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << endl;
}
