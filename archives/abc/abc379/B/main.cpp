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
    int ans = 0;
    int cnt = 0;
    rep(i, N) {
        if (S[i] == 'O') {
            cnt++;
            if (cnt == K) {
                ans++;
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }
    cout << ans << endl;
}
