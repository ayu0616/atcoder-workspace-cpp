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
    ll N, M;
    cin >> N >> M;
    vl H(N);
    cin >> H;
    ll ans = 0;
    while (M--) {
        H[ans]--;
        if (H[ans] <= 0) {
            ans++;
        }
        if (ans >= N) {
            break;
        }
    }
    cout << ans << endl;
}
