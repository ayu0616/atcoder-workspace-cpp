#include <algorithm>
#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/cumulative-sum.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M, K;
    cin >> N >> M >> K;
    vl A(N);
    cin >> A;
    vl sorted_A = A;
    sort(all(sorted_A));
    hassaku::CumulativeSum1D<ll> cs(sorted_A);
    ll border = N - M;
    if (border == 0) {
        vi ans(N, 0);
        cout << ans << endl;
        return 0;
    }
    ll border_val = sorted_A[border];
    ll rest = K - cs.get(0, N);
    ll top_sum = cs.get(border, N);
    auto solve = [&](ll i) {
        ll val = A[i];
        ll ts = top_sum;
        if (val >= border_val) {
            ts -= val;
            ts += sorted_A[border - 1];
        }
        ll l = -1, r = rest + 1;
        while (r - l > 1) {
            ll X = l + (r - l) / 2;
            ll i_result = val + X;
            ll top_result_sum = ts + rest - X;
            bool ok = (i_result+1) * M > top_result_sum;
            if (ok) {
                r = X;
            } else {
                l = X;
            }
        }
        if (r > rest) {
            return -1ll;
        }
        return r;
    };
    vl ans(N, 0);
    rep(i, N) { ans[i] = solve(i); }
    cout << ans << endl;
}
