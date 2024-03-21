#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll dp[5001][5001];

struct Task {
    ll d, c, s;
};
bool operator<(const Task &lhs, const Task &rhs) { return lhs.d < rhs.d; }

int main() {
    cout << fixed << setprecision(18);
    int N;
    cin >> N;
    vl D(N), C(N), S(N);
    rep(i, N) cin >> D[i] >> C[i] >> S[i];
    vector<Task> tasks(N);
    rep(i, N) { tasks[i] = {D[i], C[i], S[i]}; }
    sort(all(tasks));
    rep(i, 5001) rep(j, 5001) dp[i][j] = 0;
    rep(i, N) {
        rep(j, 1, 5001) {
            Task task = tasks[i];
            if (j < task.c || j > task.d) {
                dp[i + 1][j] = dp[i][j];
            } else {
                dp[i + 1][j] = max(dp[i][j], dp[i][j - task.c] + task.s);
            }
        }
    }
    ll ans = 0;
    rep(j, 5001) { chmax(ans, dp[N][j]); }
    cout << ans << endl;
}
