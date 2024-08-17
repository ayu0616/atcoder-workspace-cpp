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
    ll A, B, C;
    cin >> A >> B >> C;
    if (C < B) {
        if (C <= A && A <= B) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (A <= B || C <= A) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
