#include <numeric>
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
    int N, Q;
    cin >> N >> Q;
    vi T(Q);
    cin >> T;
    vi ok(N, 1);
    for (auto t : T) {
        ok[t - 1] = 1 - ok[t - 1];
    }
    int ans = accumulate(all(ok), 0);
    cout << ans << endl;
}
