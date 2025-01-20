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
    double e = 3.5;
    rep(N - 1) {
        double ne = 0;
        for (int d = 1; d <= 6; ++d) {
            ne += max((double)d, e);
        }
        e = ne / 6;
    }
    cout << e << endl;
}
