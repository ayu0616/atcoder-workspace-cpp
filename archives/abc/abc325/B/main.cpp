#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    vl W(N), X(N);
    rep(i, N) cin >> W[i] >> X[i];
    ll ans = 0, tmp = 0;
    rep(i, 24)
    {
        tmp = 0;
        rep(j, 9)
        {
            rep(k, N)
            {
                if (X[k] == (i + j) % 24)
                    tmp += W[k];
            }
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}
