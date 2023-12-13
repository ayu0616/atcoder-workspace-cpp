#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int D;
    cin >> D;
    vi c(26), last(26, 0);
    vvi s(D, vi(26));
    vi t(D);
    rep(i, 26) cin >> c[i];
    rep(i, D) rep(j, 26) cin >> s[i][j];
    rep(i, D) cin >> t[i];

    ll score = 0;
    rep(i, D)
    {
        score += s[i][t[i] - 1];
        last[t[i] - 1] = i + 1;
        rep(j, 26) score -= c[j] * (i + 1 - last[j]);
        cout << score << endl;
    }
}
