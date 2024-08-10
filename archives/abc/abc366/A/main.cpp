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
    ll N, T, A;
    cin >> N >> T >> A;
    if (T * 2 > N || A * 2 > N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
