#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    int ans = 0;
    for (int i = m; i <= n; i += p)
    {
        ans++;
    }
    cout << ans << endl;
}
