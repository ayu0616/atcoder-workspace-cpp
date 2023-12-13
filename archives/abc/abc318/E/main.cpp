#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    vvl ans(n + 1);
    vi tmp(n + 1, -1);
    rep(i, n)
    {
        int ai = a[i];
        if (tmp[ai] == -1)
        {
            tmp[ai] = i;
        }
        else
        {
            ans[ai].push_back(i - tmp[ai] - 1 - ans[ai].size());
        }
    }
    ll out = 0;
    rep(i, n+1) out += accumulate(all(ans[i]), 0);
    cout << out << endl;
}
