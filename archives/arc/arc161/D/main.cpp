#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, d;
    cin >> n >> d;
    string ans;
    if (n >= 2 * d + 1)
        ans = "Yes";
    else
        ans = "No";
    cout << ans << endl;
    if (ans == "No")
        return 0;

    // Graph g(n);
    rep(i, n)
    {
        rep(j, d)
        {
            int k = (i + j + 1) % n;
            cout << i + 1 << " " << k + 1 << endl;
        }
    }
}
