#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    int N, K;
    string S;
    cin >> N >> K >> S;
    int a_cnt = 0, b_cnt = 0, c_cnt = 0;
    rep(i, N)
    {
        if (S[i] == 'A')
            ++a_cnt;
        else if (S[i] == 'B')
            ++b_cnt;
        else
            ++c_cnt;
    }
    vector<mint> dp(K + 1, 0);
    dp[0] = 1;
    rep(i, K)
    {
        dp[i+1] = 
    }
}
