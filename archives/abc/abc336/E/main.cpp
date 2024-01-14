#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N;
    cin >> N;
    string S = to_string(N);
    int L = log10(N) + 1;
    int k_max = L * 9;
    ll ans = 0;
    rep(i, 1, k_max + 1) {
        vector<vector<vvl>> dp(L + 1, vector<vvl>(k_max+1, vvl(k_max+1, vl(2, 0))));
        dp[0][0][0][0] = 1;
        rep(j, L) {
            int D = S[j] - '0';
            rep(k, k_max) {
                rep(l, k_max) {
                    rep(m, 2) {
                        rep(d, 10) {
                            int nj = j + 1;
                            int nk = k + d;
                            int nl = (l + d * (ll)powl(10, L - j - 1)) % i;
                            int nm = m;
                            if (d > D) continue;
                            if (d < D) nm = 1;
                            if (d == D) nm = m;
                            if (nk > k_max) continue;
                            if (nl > k_max) continue;
                            dp[nj][nk][nl][nm] += dp[j][k][l][m];
                        }
                    }
                }
            }
        }
        ans += dp[L][i][0][0] + dp[L][i][0][1];
    }
    cout << ans << endl;
}
