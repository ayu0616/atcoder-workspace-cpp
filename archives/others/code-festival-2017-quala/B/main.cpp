#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    string ans = "No";
    int x, y;
    rep(x, m + 1)
    {
        rep(y, n + 1)
        {
            if (n * x + y * (m - 2 * x) == k)
            {
                ans = "Yes";
                break;
            }
        }
    }
    cout << ans << endl;
}
