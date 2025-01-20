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
    int N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;

    ll ans = 0;
    ll cnt = 0;

    auto solve = [&](auto&& f, ll val, int left, int rest) -> void {
        cnt++;
        if (rest == 0) {
            chmax(ans, val);
            return;
        }
        for (int i = left; i < N - rest + 1; ++i) {
            f(f, val ^ A[i], i + 1, rest - 1);
        }
    };

    if (K <= N - K) {
        solve(solve, 0, 0, K);
    } else {
        ll all_xor = 0;
        rep(i, N) all_xor ^= A[i];
        solve(solve, all_xor, 0, N - K);
    }
    // debug(cnt);
    cout << ans << endl;
}
