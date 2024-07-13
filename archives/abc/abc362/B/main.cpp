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
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll ab = pow(xb - xa, 2) + pow(yb - ya, 2);
    ll bc = pow(xc - xb, 2) + pow(yc - yb, 2);
    ll ac = pow(xc - xa, 2) + pow(yc - ya, 2);
    bool ok = ab + bc == ac || ab + ac == bc || ac + bc == ab;
    cout << (ok ? "Yes" : "No") << endl;
}
