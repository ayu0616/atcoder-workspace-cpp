#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n;

int main()
{
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)), a1(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    rep(i, n) rep(j, n) cin >> b[i][j];
    string ans = "No";
    rep(k, 4)
    {
        rep(i, n) rep(j, n) a1[i][j] = a[n - 1 - j][i];
        a = a1;
        bool f = true;
        rep(i, n) rep(j, n) {
            if(a[i][j]==1){
                f&=b[i][j]==1;
            }
        }
        if (f)
        {
            ans = "Yes";
            break;
        }
    }
    cout << ans << endl;
}
