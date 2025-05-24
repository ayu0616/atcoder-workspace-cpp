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
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    if (C < A) {
        cout << "Yes" << endl;
    } else if (C > A) {
        cout << "No" << endl;
    } else {
        if (D < B) {
            cout << "Yes" << endl;
        } else if (D > B) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
