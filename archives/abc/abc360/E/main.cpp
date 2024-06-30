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
    ll _N, K;
    cin >> _N >> K;
    mint N = _N;
    mint e = 1;
    rep(k, K) {
        mint ne = N * (N + 1) / (N * N);
        ne -= e * 2 / (N * N);
        ne += e * (mint(1) - mint(2) * (N - 1) / (N * N));
        e = ne;
    }
    cout << e.val() << endl;
}
