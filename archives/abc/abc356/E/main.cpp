#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
vl A;

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    A.resize(N);
    cin >> A;
    sort(all(A));
    vl cnt(1e6 + 10, 0);
    for (auto a : A) {
        cnt[a]++;
    }
    rep(i, 1, 1e6 + 1) { cnt[i] += cnt[i - 1]; }
    ll ans = 0;
    rep(d, 1, 1e6 + 1) {
        ll d_cnt = cnt[d] - cnt[d - 1];
        for (ll n = 1; n * d <= 1e6; n++) {
            ll f_dn = (cnt[min((ll)1e6, (n + 1) * d - 1)] - cnt[n * d - 1]) * d_cnt;
            ans += n * f_dn;
        }
        ans -= d_cnt * (d_cnt + 1) / 2;
    }
    cout << ans << endl;
}
