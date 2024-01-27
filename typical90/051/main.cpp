#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, K;
    ll P;
    cin >> N >> K >> P;
    vl A(N);
    cin >> A;

    int M = N / 2;
    vl L = vl(A.begin(), A.begin() + M), R = vl(A.begin() + M, A.end());
    vvl L_sum(K + 1), R_sum(K + 1);
    rep(S, 1LL << M) {
        ll sum = 0, cnt = 0;
        rep(i, M) {
            if (S >> i & 1) {
                sum += L[i];
                cnt++;
            }
        }
        if (cnt <= K) L_sum[cnt].emplace_back(sum);
    }
    rep(S, 1LL << (N - M)) {
        ll sum = 0, cnt = 0;
        rep(i, (N - M)) {
            if (S >> i & 1) {
                sum += R[i];
                cnt++;
            }
        }
        if (cnt <= K) R_sum[cnt].emplace_back(sum);
    }
    rep(i, K + 1) {
        sort(all(L_sum[i]));
        sort(all(R_sum[i]));
    }
    ll ans = 0;
    rep(i, K + 1) {
        for (ll l : L_sum[i]) {
            auto it = upper_bound(all(R_sum[K - i]), P - l);
            ans += it - R_sum[K - i].begin();
        }
    }
    cout << ans << endl;
}
