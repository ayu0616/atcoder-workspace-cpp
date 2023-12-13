#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M, P;
    cin >> N >> M >> P;
    vl A(N), B(M), B_diff(M), B_sum(M + 1, 0), B_sum_diff(M + 1, 0);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    sort(all(B));
    rep(i, M) B_diff[i] = B[i] - P;
    rep(i, M + 1)
    {
        if (i == 0)
            continue;
        B_sum[i] = B_sum[i - 1] + B[i - 1];
    }
    ll ans = 0;
    rep(i, N)
    {
        ll a = A[i];
        ll idx = lower_bound(all(B), P - a) - B.begin();
        ans += B_sum[idx];
        ans += a * idx;
        ans += P * (M - idx);
    }
    cout << ans << endl;
}
