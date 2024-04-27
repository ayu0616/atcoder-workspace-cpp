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
    vl X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    vl X1, Y1, X2, Y2;
    rep(i, N) {
        if (X[i] % 2 == Y[i] % 2) {
            X1.push_back((X[i] + Y[i]) / 2);
            Y1.push_back((X[i] - Y[i]) / 2);
        } else {
            X2.push_back((X[i] + Y[i]) / 2);
            Y2.push_back((X[i] - Y[i]) / 2);
        }
    }
    ll ans = 0;
    sort(all(X1));
    sort(all(Y1));
    sort(all(X2));
    sort(all(Y2));
    vl x1_sum(X1.size() + 1), y1_sum(Y1.size() + 1), x2_sum(X2.size() + 1), y2_sum(Y2.size() + 1);
    rep(i, X1.size()) x1_sum[i + 1] = x1_sum[i] + X1[i];
    rep(i, Y1.size()) y1_sum[i + 1] = y1_sum[i] + Y1[i];
    rep(i, X2.size()) x2_sum[i + 1] = x2_sum[i] + X2[i];
    rep(i, Y2.size()) y2_sum[i + 1] = y2_sum[i] + Y2[i];
    for (auto x1 : X1) {
        auto it = lower_bound(all(X1), x1);
        ll x1_s = x1_sum[it - X1.begin()];
        ll x1_l = x1_sum.back() - x1_s;
        ll x1_r = x1_s;
        ll x1_ans = x1_l + x1_r - x1 * (X1.size() - (it - X1.begin())) + x1 * (it - X1.begin());
        ans += x1_ans;
    }
    for (auto y1 : Y1) {
        auto it = lower_bound(all(Y1), y1);
        ll y1_s = y1_sum[it - Y1.begin()];
        ll y1_l = y1_sum.back() - y1_s;
        ll y1_r = y1_s;
        ll y1_ans = y1_l + y1_r - y1 * (Y1.size() - (it - Y1.begin())) + y1 * (it - Y1.begin());
        ans += y1_ans;
    }
    for (auto x2 : X2) {
        auto it = lower_bound(all(X2), x2);
        ll x2_s = x2_sum[it - X2.begin()];
        ll x2_l = x2_sum.back() - x2_s;
        ll x2_r = x2_s;
        ll x2_ans = x2_l + x2_r - x2 * (X2.size() - (it - X2.begin())) + x2 * (it - X2.begin());
        ans += x2_ans;
    }
    for (auto y2 : Y2) {
        auto it = lower_bound(all(Y2), y2);
        ll y2_s = y2_sum[it - Y2.begin()];
        ll y2_l = y2_sum.back() - y2_s;
        ll y2_r = y2_s;
        ll y2_ans = y2_l + y2_r - y2 * (Y2.size() - (it - Y2.begin())) + y2 * (it - Y2.begin());
        ans += y2_ans;
    }
    cout << ans / 2 << endl;
}
