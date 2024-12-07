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
    ll H, W, D;
    cin >> H >> W >> D;
    ll ans = 0;
    vs S(H);
    cin >> S;

    rep(i1, H) rep(j1, W) {
        if (S[i1][j1] == '#') continue;
        rep(i2, H) rep(j2, W) {
            if (i1 == i2 && j1 == j2) continue;
            if (S[i2][j2] == '#') continue;
            set<pair<ll, ll>> st;
            rep(i, H) rep(j, W) {
                if (S[i][j] == '#') continue;
                if (abs(i - i1) + abs(j - j1) <= D) {
                    st.insert({i, j});
                }
                if (abs(i - i2) + abs(j - j2) <= D) {
                    st.insert({i, j});
                }
            }
            chmax(ans, (ll)st.size());
        }
    }

    cout << ans << endl;
}
