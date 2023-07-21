#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m + 1)
    {
        if (j == 0)
            cin >> c[i];
        else
            cin >> a[i][j - 1];
    }

    int ans = 1e9;

    for (int bit = 0; bit < (1 << n); ++bit){
        vector<int> sum(m);
        int cost = 0;
        rep(i, n) if (bit & (1 << i)){
            cost += c[i];
            rep(j, m) sum[j] += a[i][j];
        }
        bool ok = true;
        rep(i, m) if (sum[i] < x) ok = false;
        if (ok){
            ans = min(ans, cost);
        }
    }
    if(ans==1e9) ans = -1;
    cout << ans << endl;
}
