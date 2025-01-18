#include <numeric>
#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

using P = pll;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl P(N);
    cin >> P;
    ll cnt = 0;
    vl ans(N);
    priority_queue<pll, vector<pll>, greater<pll>> q;
    rep(i, N) {
        ll c = ans[i];
        ll diff = P[i] * ((c + 1) * (c + 1) - c * c);
        q.push({diff, i});
    }
    while (cnt + q.top().first < M) {
        auto [diff, i] = q.top();
        q.pop();
        ll ok = 1e9;
        ll ng = 0;
        auto [diff2, i2] = q.top();
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            ll x = ans[i] + mid;
            if (P[i] * ((x + 1) * (x + 1) - x * x) >= diff2) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cnt += P[i] * ((ans[i] + ok) * (ans[i] + ok) - ans[i] * ans[i]);
        ans[i] += ok;
        q.push({P[i] * ((ans[i] + 1) * (ans[i] + 1) - ans[i] * ans[i]), i});
    }
    cout << accumulate(all(ans), 0LL) << endl;
}
