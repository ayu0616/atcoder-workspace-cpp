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
    string N;
    cin >> N;
    char a = N[0], b = N[1], c = N[2];
    cout << b << c << a << " " << c << a << b << endl;
}
