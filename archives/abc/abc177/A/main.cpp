#ifdef HASSAKU_DEBUG
#define _GLIBCXX_DEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int D, T, S;
    cin >> D >> T >> S;
    cout << (T * S >= D ? "Yes" : "No") << endl;
}
