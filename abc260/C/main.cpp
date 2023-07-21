#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

ll n, x, y;
ll r(int k);
ll b(int k);

ll stones[11][2];

ll r(int k)
{
    if (n == k)
    {
        return 1;
    }
    else
    {
        return r(k + 1) + b(k + 1);
    }
}

ll b(int k)
{
    if (n == k)
    {
        return x * r(k);
    }
    else
    {
        return (x + y) * r(k) + y * r(k + 1);
    }
}

int main()
{
    cin >> n >> x >> y;
    rep(i, 11) rep(j, 2) stones[i][j] = 0;
    stones[n][0] = 1;
    for (int i = n; i >= 2; i--)
    {
        stones[i][1] += stones[i][0] * x;
        stones[i - 1][0] += stones[i][0];
        stones[i][0] = 0;

        stones[i - 1][0] += stones[i][1];
        stones[i - 1][1] += stones[i][1] * y;
        stones[i][1] = 0;
    }
    cout << stones[1][1] << endl;
    // show_multi_array(stones, 11, 2);
}
