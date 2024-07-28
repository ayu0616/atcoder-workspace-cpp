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
    ll N, X, Y;
    cin >> N >> X >> Y;
    vpll AB(N);
    rep(i, N) { cin >> AB[i].first >> AB[i].second; }
    sort(all(AB));
    vl A(N), B(N);
    rep(i, N) {
        A[i] = AB[i].first;
        B[i] = AB[i].second;
    }
    ll dp[N + 1][N + 1][20010];
    rep(i, N + 1) rep(j, N + 1) rep(k, 20010) { dp[i][j][k] = LL_INF; }
    dp[0][0][0] = 0;
    ll ans = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, 20010) {
                chmin(dp[i + 1][j][k], dp[i][j][k]);
                if (k <= X && k + A[i] < 20010 && dp[i][j][k] <= Y) {
                    if (chmin(dp[i + 1][j + 1][k + A[i]], dp[i][j][k] + B[i])) {
                        chmax(ans, j + 1);
                    }
                }
            }
        }
    }
    vpll BA(N);
    rep(i, N) { BA[i] = {B[i], A[i]}; }
    sort(all(BA));
    rep(i, N) {
        B[i] = BA[i].first;
        A[i] = BA[i].second;
    }
    swap(A, B);
    swap(X, Y);
    rep(i, N + 1) rep(j, N + 1) rep(k, 20010) { dp[i][j][k] = LL_INF; }
    dp[0][0][0] = 0;
    rep(i, N) {
        rep(j, N) {
            rep(k, 20010) {
                chmin(dp[i + 1][j][k], dp[i][j][k]);
                if (k <= X && k + A[i] < 20010 && dp[i][j][k] <= Y) {
                    if (chmin(dp[i + 1][j + 1][k + A[i]], dp[i][j][k] + B[i])) {
                        chmax(ans, j + 1);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
