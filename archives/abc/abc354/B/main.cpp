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
    vs S(N);vl C(N);
    rep(i, N) cin >> S[i] >> C[i];
    ll T = 0;
    rep(i, N) { T += C[i]; }
    sort(all(S));
    cout << S[T % N] << endl;
}
