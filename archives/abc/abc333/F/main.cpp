#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vector<vector<mint>> dp(N, vector<mint>(N, 0));
    rep(i, N) rep(n, N) {
        mint a = 1;
        a /= powl(2, n);
        mint r = 1;
        r /= powl(2, N - i);
    }
    cout << ans << endl;
}
