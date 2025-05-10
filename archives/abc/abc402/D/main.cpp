#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl A(M), B(M);
    rep(i, M) {
        cin >> A[i] >> B[i];
        A[i]--;
        B[i]--;
    }
    vl cnt(N);
    rep(i, M) { cnt[(A[i] + B[i]) % N]++; }
    ll ans = M * (M - 1) / 2;
    rep(i, N) { ans -= cnt[i] * (cnt[i] - 1) / 2; }
    cout << ans << endl;
}
