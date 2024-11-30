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
    ll N, D;
    string S;
    cin >> N >> D >> S;
    ll ans = D;
    rep(i, N) {
        if (S[i] == '.') ans++;
    }
    cout << ans << endl;
}
