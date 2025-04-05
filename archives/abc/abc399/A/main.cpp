#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    string S, T;
    cin >> N >> S >> T;
    int ans = 0;
    rep(i, N) { ans += S[i] != T[i]; }
    cout << ans << endl;
}
