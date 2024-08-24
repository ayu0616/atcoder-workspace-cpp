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
    ll N;
    cin >> N;
    vl H(N);
    cin >> H;
    ll T = 0;
    for (ll h : H) {
        ll a = h / 5;
        T += a * 3;
        h -= a * 5;
        while (h > 0) {
            T++;
            if (T % 3 == 0) {
                h-=3;
            } else {
                h--;
            }
        }
    }
    cout << T << endl;
}
