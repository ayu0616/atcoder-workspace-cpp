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
    ll N, K;
    cin >> N >> K;
    vi A(N);
    cin >> A;
    vi B1(A.begin(), A.end() - K), B2(A.end() - K, A.end());
    B2.insert(B2.end(), B1.begin(), B1.end());
    cout << B2 << endl;
}
