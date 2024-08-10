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
    ll N, D;
    cin >> N >> D;
    vl x(N), y(N);
    rep(i, N) { cin >> x[i] >> y[i]; }
    vl x_ans(D + 1), y_ans(D + 1);
    sort(all(x)), sort(all(y));
    ll xs = *x.begin() - D;
    ll d = 0;
    for (ll xi : x) {
        d += abs(xi - xs);
    }
    if (d <= D) {
        x_ans[d]++;
    }
    for (ll i = *x.begin() - D + 1; i <= *x.rbegin() + D; ++i) {
        auto cnt = lower_bound(all(x), i) - x.begin();
        d += cnt;
        d -= N - cnt;
        if (d <= D) {
            x_ans[d]++;
        }
    }
    ll ys = *y.begin() - D;
    d = 0;
    for (ll yi : y) {
        d += abs(yi - ys);
    }
    if (d <= D) {
        y_ans[d]++;
    }
    for (ll i = *y.begin() - D + 1; i <= *y.rbegin() + D; ++i) {
        auto cnt = lower_bound(all(y), i) - y.begin();
        d += cnt;
        d -= N - cnt;
        if (d <= D) {
            y_ans[d]++;
        }
    }
    ll ans = 0;
    vl y_ans_sum(D + 1);
    rep(i, D + 1) { y_ans_sum[i] = y_ans[i] + (i ? y_ans_sum[i - 1] : 0); }
    rep(i, D + 1) { ans += x_ans[i] * y_ans_sum[D - i]; }
    cout << ans << endl;
}
