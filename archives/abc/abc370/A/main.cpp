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
    ll L, R;
    cin >> L >> R;
    if (L == R) {
        cout << "Invalid" << endl;
    } else if (L == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
