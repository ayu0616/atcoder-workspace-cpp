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
    ll H;
    cin >> H;
    ll height = 0;
    ll i = 0;
    while (height <= H) {
        height += powl(2LL, i);
        i++;
    }
    cout << i << endl;
}
