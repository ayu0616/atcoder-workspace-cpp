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
    vl q(N), r(N);
    rep(i, N) { cin >> q[i] >> r[i]; }
    int Q;
    cin >> Q;
    while (Q--) {
        int t, d;
        cin >> t >> d;
        t--;
        ll qt = q[t];
        ll rt = r[t];

        ll div = d / qt;

        ll ans = div * qt + rt;
        while(ans < d) {
            ans += qt;
        }

        cout << ans << endl;
    }
}
