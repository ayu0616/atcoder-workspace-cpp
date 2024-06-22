#include <cassert>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    if (sx > tx) {
        swap(sx, tx);
        swap(sy, ty);
    }
    if (abs(sy) % 2 == 0 && abs(sx) % 2 == 1) {
        sx--;
    }
    if (abs(sy) % 2 == 1 && abs(sx) % 2 == 0) {
        sx--;
    }
    if (abs(ty) % 2 == 0 && abs(tx) % 2 == 1) {
        tx--;
    }
    if (abs(ty) % 2 == 1 && abs(tx) % 2 == 0) {
        tx--;
    }
    assert(abs(sx + sy) % 2 == 0);
    assert(abs(tx + ty) % 2 == 0);
    ll dx = tx - sx;
    ll dy = ty - sy;
    ll ans = 0;
    if (abs(dx) < abs(dy)) {
        ans += abs(dy);
    } else {
        ans += abs(dy);
        sx += abs(dy);
        dx = tx - sx;
        ans += dx / 2;
        // ll minx = min(sx, tx);
        // ll maxx = max(sx, tx);
        // if (abs(sy) % 2 == abs(ty) % 2) {
        //     if (abs(sy) % 2 == 0 && abs(minx) % 2 == 1 && abs(maxx) % 2 == 0) {
        //         ans += 1;
        //     }
        //     if (abs(sy) % 2 == 1 && abs(minx) % 2 == 0 && abs(maxx) % 2 == 1) {
        //         ans += 1;
        //     }
        // } else {
        //     if (abs(sy) % 2 == 0 && abs(minx) % 2 == 0 && abs(maxx) % 2 == 0) {
        //         ans -= 1;
        //     }
        //     if (abs(sy) % 2 == 1 && abs(minx) % 2 == 1 && abs(maxx) % 2 == 1) {
        //         ans -= 1;
        //     }
        // }
    }
    cout << ans << endl;
}
