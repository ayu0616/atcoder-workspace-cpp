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
    ll N, L, R;
    cin >> N >> L >> R;
    vl ans(N);
    iota(all(ans), 1);
    reverse(ans.begin() + L - 1, ans.begin() + R);
    cout << ans << endl;
}
