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
    int N;
    cin >> N;
    vl A(N), C(N);
    rep(i, N) cin >> A[i] >> C[i];
    map<ll, ll> mp;
    rep(i, N) { mp[C[i]] = 1e10; }
    rep(i, N) { chmin(mp[C[i]], A[i]); }
    ll ans = 0;
    rep(i, N) { chmax(ans, mp[C[i]]); }
    cout << ans << endl;
}
