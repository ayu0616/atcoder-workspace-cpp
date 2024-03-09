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
    string T;
    int N;
    cin >> T >> N;
    vector<vs> S(N);
    rep(i, N) {
        int a;
        cin >> a;
        rep(j, a) {
            string t;
            cin >> t;
            S[i].push_back(t);
        }
    }
    int dp[101][101];
    rep(i, 101) rep(j, 101) dp[i][j] = INT_INF;
    rep(i, 101) dp[i][0] = 0;
    rep(i, N) {
        rep(j, 101) dp[i + 1][j] = dp[i][j];
        rep(j, S[i].size()) {
            rep(k, T.size()) {
                if (k + S[i][j].size() > T.size()) continue;
                bool ok = true;
                rep(l, S[i][j].size()) {
                    if (T[k + l] != S[i][j][l]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    chmin(dp[i + 1][k + S[i][j].size()], dp[i][k] + 1);
                }
            }
        }
    }
    int ans = dp[N][T.size()];
    cout << (ans == INT_INF ? -1 : ans) << endl;
}
