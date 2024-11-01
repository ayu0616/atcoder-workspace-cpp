#include <algorithm>
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
    ll N, Q;
    string S;
    cin >> N >> Q >> S;
    int ans = 0;
    rep(i, N - 2) {
        if (S.substr(i, 3) == "ABC") {
            ans++;
        }
    }
    while (Q--) {
        ll X;
        char C;
        cin >> X >> C;
        X--;
        int diff = S[X] - 'A';
        if ((S[X] == 'A' || S[X] == 'B' || S[X] == 'C') && X - diff >= 0) {
            if (S.substr(X - diff, 3) == "ABC") {
                ans--;
            }
        }
        S[X] = C;
        diff = S[X] - 'A';
        if ((C == 'A' || C == 'B' || C == 'C') && X - diff >= 0) {
            if (S.substr(X - diff, 3) == "ABC") {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
