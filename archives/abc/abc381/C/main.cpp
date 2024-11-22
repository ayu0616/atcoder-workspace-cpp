#include <cassert>
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
    string S;
    cin >> N >> S;
    int ans = 0;
    int len1 = 0, len2 = 0;
    int state = -1;
    rep(i, N) {
        if (S[i] == '1') {
            if (state != 0) {
                state = 0;
                len1 = 0;
                len2 = 0;
            }
            len1++;
        } else if (S[i] == '2') {
            if (state == 1) {
                state = 2;
            } else if(state != 2) {
                state = -1;
                continue;
            }
            len2++;
            chmax(ans, min(len1, len2)*2+1);
        } else {
            chmax(ans, 1);
            if(state == 0) {
                state = 1;
            } else {
                state = -1;
            }
        }
    }
    cout << ans << endl;
}
