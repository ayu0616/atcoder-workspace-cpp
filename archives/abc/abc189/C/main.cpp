#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int cnt, mi, ans = 0;
    for (int i = 0; i < n; i++)
    {
        mi = a[i];
        for (int j = i; j < n; j++)
        {
            cnt = j - i + 1;
            mi = min(a[j], mi);
            ans = max(ans, mi * cnt);
        }
    }
    cout << ans << endl;
}
