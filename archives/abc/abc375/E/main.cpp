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
    vi A(N), B(N);
    rep(i, N) cin >> A[i] >> B[i];

    const int bsum = accumulate(all(B), 0);

    if (bsum % 3 != 0) {
        cout << -1 << endl;
        return 0;
    }

    const int bmax = bsum / 3;

    vector dp(bmax + 1, vector(bmax + 1, INT_INF));
    dp[0][0] = 0;

    rep(i, N) {
        const int a = A[i], b = B[i];
        vector next(bmax + 1, vector(bmax + 1, INT_INF));
        rep(j, bmax + 1) {
            rep(k, bmax + 1) {
                if (dp[j][k] == INT_INF) continue;
                if (j + b <= bmax) {
                    chmin(next[j + b][k], dp[j][k] + (a != 1));
                }
                if (k + b <= bmax) {
                    chmin(next[j][k + b], dp[j][k] + (a != 2));
                }
                chmin(next[j][k], dp[j][k] + (a != 3));
            }
        }
        swap(dp, next);
    }

    int ans = dp[bmax][bmax];

    if (ans == INT_INF) {
        ans = -1;
    }

    cout << ans << endl;
}
