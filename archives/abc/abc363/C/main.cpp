#include <string>
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
    string S;
    cin >> N >> K >> S;
    ll ans = 0;
    sort(all(S));
    do {
        bool ok = false;
        rep(i, N - K + 1) {
            bool is_kaibun = true;
            rep(j, K) {
                if (S[i + j] != S[i + K - j - 1]) {
                    is_kaibun = false;
                    break;
                }
            }
            if (is_kaibun) {
                ok = true;
                break;
            }
        }
        if (!ok) {
            ans++;
        }
    } while (next_permutation(all(S)));
    cout << ans << endl;
}
