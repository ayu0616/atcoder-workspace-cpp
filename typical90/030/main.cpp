#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N, K;
    cin >> N >> K;
    vl c(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        if (c[i]) continue;
        for (int j = i; j <= N; j += i) c[j]++;
    }
    ll ans = 0;
    for (int i = 2; i <= N; i++)
        if (c[i] >= K) ans++;
    cout << ans << endl;
}
