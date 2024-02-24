#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M, K;
    cin >> N >> M >> K;
    ll lcm_n_m = lcm(N, M);
    ll l = 0, r = 1e18;
    while (r - l > 1) {
        ll c = (r + l) / 2;
        ll cnt = c / N + c / M - c / lcm_n_m * 2;
        if (cnt >= K)
            r = c;
        else
            l = c;
    }
    cout << r << endl;
}
