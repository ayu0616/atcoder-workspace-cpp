#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;
    vi p(n);
    rep(i, n) cin >> p[i];
    int ans = -1;
    rep(i, n - 1)
    {
        if (p[i + 1] >= p[0])
            ans = max(ans, p[i + 1] - p[0]);
    }
    cout << ans+1 << endl;
}
