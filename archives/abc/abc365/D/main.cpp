#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

map<char, int> mp = {{'R', 0}, {'S', 1}, {'P', 2}};
const string RSP = "RSP";

int main() {
    cout << fixed << setprecision(18);
    ll N;
    string S;
    cin >> N >> S;
    ll dp[N + 1][3];
    rep(i, N + 1) rep(j, 3) dp[i][j] = 0;
    rep(i, N) {
        int aoki = mp[S[i]];
        int t1 = (aoki + 2) % 3;
        int t2 = aoki;
        rep(j, 3) {
            if (j == t1) continue;
            dp[i + 1][t1] = max(dp[i + 1][t1], dp[i][j] + 1);
        }
        rep(j, 3) {
            if (j == t2) continue;
            dp[i + 1][t2] = max(dp[i + 1][t2], dp[i][j]);
        }
    }
    cout<<max({dp[N][0], dp[N][1], dp[N][2]})<<endl;
}
