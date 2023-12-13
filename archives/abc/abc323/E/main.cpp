#include "../../lib.hpp"

const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    ll N, X;
    cin >> N >> X;
    vl T(N);
    rep(i, N) cin >> T[i];
    vector<mint> P(X + 1, 0);
    P[0] = 1;
    rep(t, 1, X + 1)
    {
        rep(i, N)
        {
            if (t - T[i] >= 0)
            {
                P[t] += P[t - T[i]] / N;
            }
        }
    }
    mint ans = 0;
    rep(t, max(0, X - T[0] + 1), X + 1)
    {
        ans += P[t];
    }
    cout << ans / N << endl;
}
