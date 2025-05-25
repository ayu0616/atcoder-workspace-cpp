#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll X, Y;
    cin >> X >> Y;
    ll cnt = 0;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j >= X || abs(i - j) >= Y) {
                cnt++;
            }
        }
    }
    double ans = (double)cnt / 36;
    cout << ans << endl;
}
