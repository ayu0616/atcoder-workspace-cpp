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
    rep(i, 1, N) {
        if (H[0] < H[i]) {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
