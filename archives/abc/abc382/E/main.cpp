#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vector<double> get_p(int N, vector<double> &P) {
    // dp[i][j]: iまでみて、レアカードがj枚入っている確率
    vector<vector<double>> dp(N + 1, vector<double>(N + 1, 0));
    dp[0][0] = 1;
    rep(i, N) {
        rep(j, N) {
            double p = P[i] / 100;
            dp[i + 1][j] += (dp[i][j] * (1 - p));
            dp[i + 1][j + 1] += dp[i][j] * p;
        }
    }
    // p[c]: 1パックにc枚のレアカードが入っている確率
    vector<double> p = dp.back();
    return p;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, X;
    cin >> N >> X;
    vector<double> P(N);
    cin >> P;
    vector<double> p = get_p(N, P);
    double e = 0;
    rep(i, N + 1) { e += i * p[i]; }
    cout << (double)X / e << endl;

    // constexpr int pack_cnt = 200;
    // vector<vector<double>> dp(pack_cnt, vector<double>(X + 1, 0.0));
    // dp[0][0] = 1;
    // rep(i, pack_cnt - 1) {
    //     rep(j, X) {
    //         rep(c, N + 1) {
    //             int x = min(X, j + c);
    //             dp[i + 1][x] += dp[i][j] * p[c];
    //         }
    //     }
    // }

    // double ans = 0;
    // rep(i, pack_cnt) { ans += dp[i][X] * i; }
    // cout << ans << endl;
}
