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
    ll X;
    cin >> X;
    ll cur = 1;
    for (int i = 1; i < 100; i++) {
        cur *= i;
        if (cur == X) {
            cout << i << endl;
            return 0;
        }
    }
}
