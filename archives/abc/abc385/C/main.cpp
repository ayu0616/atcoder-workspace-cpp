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
    vl H(N);
    cin >> H;
    ll ans = 1;
    rep(i, N) {
        ll h = H[i];
        rep(j, 1, N) {
            ll cnt = 1;
            ll k = i + j;
            while (k < N && H[k] == h) {
                cnt++;
                k += j;
            }
            chmax(ans, cnt);
        }
    }
    cout << ans << endl;
}
