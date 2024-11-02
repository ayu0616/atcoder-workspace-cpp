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
    vi A(4);
    cin >> A;
    sort(all(A));
    int ans = 0;
    if (A[0] == A[1] && A[2] == A[3]) {
        ans = 2;
    } else if (A[0] == A[1] || A[2] == A[3] || A[1] == A[2]) {
        ans = 1;
    } else {
        ans = 0;
    }

    cout << ans << endl;
}
