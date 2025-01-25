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
    vl A(5);
    cin >> A;
    vl sorted = A;
    sort(ALL(sorted));
    rep(i, 4) {
        vl B = A;
        swap(B[i], B[i + 1]);
        if (B == sorted) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
