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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans = 0;
    rep(i, N - 2) {
        if (S[i] == '#' && S[i + 1] == '.' && S[i + 2] == '#') {
            ans++;
        }
    }
    cout << ans << endl;
}
