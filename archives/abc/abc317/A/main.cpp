#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, h, x;
    cin >> n >> h >> x;
    vi p(n);
    rep(i, n) cin >> p[i];
    rep(i, n)
    {
        if (p[i] + h >= x)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
