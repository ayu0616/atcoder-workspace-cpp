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
    ll N, C;
    cin >> N >> C;
    vi T(N);
    cin >> T;
    int prev = T[0];
    int ans = 0;
    rep(i, 1, N) {
        if (T[i] - prev >= C) {
            ans++;
            prev = T[i];
        }
    }
    cout << ans + 1 << endl;
}
