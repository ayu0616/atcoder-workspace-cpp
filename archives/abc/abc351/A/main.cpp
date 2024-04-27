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
    vl A(9), B(8);
    cin >> A >> B;
    ll a_sum = accumulate(all(A), 0LL);
    ll b_sum = accumulate(all(B), 0LL);
    cout << a_sum - b_sum + 1 << endl;
}
