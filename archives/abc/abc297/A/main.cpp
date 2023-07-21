#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n;
ll d, t[101];

int main()
{
    cin >> n >> d;
    rep(i, n) cin >> t[i];
    rep(i, n - 1)
    {
        if (t[i + 1] - t[i] <= d)
        {
            cout << t[i + 1] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
