#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, H;
    cin >> N >> H;
    vl X(N), P(N - 1), F(N - 1);
    rep(i, N) cin >> X[i];
    rep(i, N - 1) cin >> P[i] >> F[i];

    vector<vector<pll>> dp(2 * N, vector<pll>(2));
    dp[0][0] = pll(1e9, H);
    vector<bool> used(N, false);

    rep2(i,1, 2*N-1){
        if(i==N-1){
            dp[i][0] = {dp[i-1][0].first + P[i-1], dp[i-1][0].second + F[i-1]};
        }else if(used[min(i, 2*N-i)]){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
        }else{

        }
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;
}
