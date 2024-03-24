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
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    vi B(N - 1);
    rep(i, N - 1) { B[i] = A[i + 1] * A[i]; }
    cout << B << endl;
}
