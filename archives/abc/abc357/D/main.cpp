#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    ll ln = 0;
    ll N_ = N;
    while (N_ > 0) {
        N_ /= 10;
        ln++;
    }
    mint a = N;
    mint r = mint(10).pow(ln);
    cout << a * (r.pow(N) - 1) / (r - 1) << endl;
}
