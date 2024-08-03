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
    if (N % 4 != 0) {
        cout << 365 << endl;
        return 0;
    }
    if (N % 100 != 0) {
        cout << 366 << endl;
        return 0;
    }
    if (N % 400 != 0) {
        cout << 365 << endl;
        return 0;
    }
    cout << 366 << endl;
    return 0;
}
