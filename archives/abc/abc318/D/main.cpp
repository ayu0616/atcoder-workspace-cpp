#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N;
    cin >> N;
    vvl G(N, vl(N, 0));
    rep(i, N - 1)
    {
        rep2(j, i + 1, N)
        {
            ll d;
            cin >> d;
            G[i][j] = d;
            G[j][i] = d;
        }
    }
    vl dp(1 << N, 0);
    rep(b, 1 << N)
    {
        int l = -1;
        rep(i, N) if (!(b >> i & 1))
        {
            l = i;
            break;
        }
        rep(i, N) if (!(b >> i & 1))
        {
            int nb = b | (1 << l) | (1 << i);
            dp[nb] = max(dp[nb], dp[b] + G[l][i]);
        }
    }
    cout << dp.back() << endl;
}
