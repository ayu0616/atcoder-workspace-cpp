#include <algorithm>
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
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;
    rep(i, N) { A[i] %= M; }
    vl A_sum(N);
    rep(i, N - 1) { A_sum[i + 1] = (A_sum[i] + A[i]) % M; }
    vector<vector<ll>> cnt(M);
    rep(i, 1, N) { cnt[A_sum[i]].push_back(i); }
    ll ans = 0;
    rep(i, M) {
        ll m = A_sum[i];
        ll diff = (M + m) % M;
        if (cnt[diff].size() > 0) {
            ans += cnt[diff].size() - (lower_bound(all(cnt[diff]), i) - cnt[diff].begin());
        }
        m = (m + A_sum.back()) % M;
        diff = (M + m) % M;
        if (cnt[diff].size() > 0) {
            ans += lower_bound(all(cnt[diff]), i) - cnt[diff].begin();
        }
    }
    cout << ans << endl;
}
