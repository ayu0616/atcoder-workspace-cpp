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
    ll N, R;
    cin >> N >> R;
    rep(N) {
        ll D, A;
        cin >> D >> A;
        if (D == 1) {
            if (1600 <= R && R < 2800) {
                R += A;
            }
        }
        if (D == 2) {
            if (1200 <= R && R < 2400) {
                R += A;
            }
        }
    }
    cout<<R<<endl;
}
