#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, ans,m;
    cin >> n;
    m = n / 5;
    if(n-m*5<(m+1)*5-n)
        ans = m*5;
    else
        ans = (m+1)*5;
    cout << ans << endl;
}
