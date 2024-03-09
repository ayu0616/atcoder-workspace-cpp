#include <iostream>
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
    vi A;
    while (true) {
        int a;
        cin >> a;
        A.push_back(a);
        if (a == 0) {
            reverse(all(A));
            rep(i, A.size()) cout << A[i] << endl;
            break;
        }
    }
}
