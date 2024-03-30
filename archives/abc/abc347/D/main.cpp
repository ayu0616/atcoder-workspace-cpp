#include <cassert>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;
ll a, b, C;

int main() {
    cout << fixed << setprecision(18);
    cin >> a >> b >> C;
    ll a_cp = a;
    ll b_cp = b;
    int c_cnt = __builtin_popcountll(C);
    ll x = 0, y = 0;
    int i = 0;
    while (a > b && i < 61) {
        if (C & (1LL << i)) {
            x |= 1LL << i;
            a--;
        }
        i++;
    }
    while (a < b && i < 61) {
        if (C & (1LL << i)) {
            y |= 1LL << i;
            b--;
        }
        i++;
    }
    rep(j, i, 61) {
        if (C & (1LL << j)) {
            if (a > b) {
                x |= 1LL << j;
                a--;
            } else {
                y |= 1LL << j;
                b--;
            }
        }
    }
    if (a != b) {
        cout << -1 << endl;
        return 0;
    }
    rep(i, 61) {
        if (a == 0 && b == 0) break;
        if (x >> i & 1 || y >> i & 1) continue;
        x |= 1LL << i;
        y |= 1LL << i;
        a--;
        b--;
    }
    if (a != 0 || b != 0) {
        cout << -1 << endl;
        return 0;
    }
    assert(__builtin_popcountll(x) == a_cp);
    assert(__builtin_popcountll(y) == b_cp);
    assert((x ^ y) == C);
    cout << x << " " << y << endl;
}
