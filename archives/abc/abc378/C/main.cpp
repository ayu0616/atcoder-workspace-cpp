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
    vl A(N);
    cin >> A;
    map<ll, int> mp;
    rep(i, N) mp[A[i]] = -1;
    vl ans(N);
    rep(i, N) {
        ans[i] = mp[A[i]];
        mp[A[i]] = i + 1;
    }
    cout << ans << endl;
}
