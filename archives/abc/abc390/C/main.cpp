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
    ll H, W;
    cin >> H >> W;
    vs S(H);
    cin >> S;
    ll minh = H, maxh = -1;
    ll minw = W, maxw = -1;
    rep(i, H) {
        rep(j, W) {
            if (S[i][j] == '#') {
                chmin(minh, i);
                chmax(maxh, i);
                chmin(minw, j);
                chmax(maxw, j);
            }
        }
    }
    rep(i, H) rep(j, W) {
        if (S[i][j] == '.' && (minh <= i && i <= maxh) && (minw <= j && j <= maxw)) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
