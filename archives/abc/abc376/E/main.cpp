#include <algorithm>
#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

void solve() {
    ll N, K;
    cin >> N >> K;
    vl A(N), B(N);
    cin >> A >> B;
    vpll v(N);
    rep(i, N) { v[i] = {B[i], i}; }
    sort(all(v));
    ll b_sum = 0;
    ll a_max = 0;
    ll b_max = 0;
    rep(i, K) {
        b_sum += v[i].first;
        chmax(a_max, A[v[i].second]);
        chmax(b_max, B[v[i].second]);
    }
    ll ans = b_sum * a_max;
    rep(i, K, N) {
        b_sum += v[i].first - b_max;
        if (chmin(ans, max(a_max, A[v[i].second]) * b_sum)) {
            chmax(a_max, A[v[i].second]);
            b_max = v[i].first;
        } else {
            b_sum -= v[i].first - b_max;
        }
    }
    cout << ans << endl;
}

int main() {
    cout << fixed << setprecision(18);
    int T;
    cin >> T;
    rep(T) { solve(); }
}
