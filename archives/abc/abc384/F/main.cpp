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
    map<vl, ll> suf_cnt;
    rep(i, N) {
        vl cur;
        for (int j = 0; j < 32; j++) {
            if (A[i] < (1LL << j)) {
                break;
            }
            cur.push_back(((A[i] >> j) & 1));
            suf_cnt[cur]++;
        }
    }
    ll ans = accumulate(all(A), 0LL) * (N + 1);
    rep(i, N) {
        vl cur;
        ll val = 0;
        for (int j = 0; j < 32; j++) {
            cur.push_back(((A[i] >> j) & 1));
            val += cur[j];
            vl inv_cur;
            ll inv_val = (1LL << (j + 1)) - val;
            for (int k = 0; k < j; k++) {
                inv_cur.push_back(((inv_val >> k) & 1) << k);
            }
            ans -= (val + inv_val) * suf_cnt[inv_cur];
        }
    }
    cout << ans << endl;
}
