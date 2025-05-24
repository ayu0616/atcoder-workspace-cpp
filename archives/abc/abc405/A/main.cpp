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
    ll R, X;
    cin >> R >> X;
    if (X == 1) {
        cout << (1600 <= R && R <= 2999 ? "Yes" : "No") << endl;
    } else {
        cout << (1200 <= R && R <= 2399 ? "Yes" : "No") << endl;
    }
}
