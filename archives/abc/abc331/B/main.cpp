#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, S, M, L;
    cin >> N >> S >> M >> L;
    ll ans = 1e9;
    rep(i, N + 13) rep(j, N + 13) rep(k, N + 13) {
        if (i * 6 + j * 8 + k * 12 < N) continue;
        chmin(ans, S * i + M * j + L * k);
    }
    cout << ans << endl;
}
