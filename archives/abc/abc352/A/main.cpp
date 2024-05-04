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
    ll N, X, Y, Z;
    cin >> N >> X >> Y >> Z;
    if (min(X, Y) < Z && Z < max(X, Y)) {
        print("Yes");
    } else {
        print("No");
    }
}
