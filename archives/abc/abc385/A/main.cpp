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
    ll a,b,c;
    cin >> a >> b >> c;
    if (a + b == c) {
        cout << "Yes" << endl;
    } else if (b+c == a) {
        cout << "Yes" << endl;
    } else if (c+a == b) {
        cout << "Yes" << endl;
    } else if (a==b && b==c) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
