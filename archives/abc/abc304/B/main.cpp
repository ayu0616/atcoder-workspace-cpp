#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    cin >> n;

    if (n < 1e3)
    {
        cout << n << endl;
    }
    else
    {
        int l = log10(n);
        int tmp = n / pow(10, l - 2);
        int ans = tmp * pow(10, l - 2);
        cout << ans << endl;
    }
}
