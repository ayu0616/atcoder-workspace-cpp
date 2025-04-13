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
    cin >> N;
    vs S(N);
    cin >> S;
    bool ok = false;
    int ans = 0;
    rep(i, N) {
        string s = S[i];
        if (s == "login") {
            ok = true;
        } else if (s == "logout") {
            ok = false;
        } else if (s == "private") {
            if (!ok) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}
