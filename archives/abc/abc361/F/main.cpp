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
    ll ans = 1;
    rep(i, 2, sqrtl(N) + 1) {
        int l = 1, r = 62;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (powl(i, m) <= N) {
                l = m;
            } else {
                r = m;
            }
        }
        ans+=l-1;
    }
    cout<<ans<<endl;
}
