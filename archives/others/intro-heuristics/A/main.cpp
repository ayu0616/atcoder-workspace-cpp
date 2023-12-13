#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int D;
    cin >> D;
    vi c(26);
    vvi s(D, vi(26));
    rep(i, 26) cin >> c[i];
    rep(i, D) rep(j, 26) cin >> s[i][j];
}
