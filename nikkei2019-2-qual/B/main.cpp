#include "../../lib.hpp"

const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

using mint = static_modint<MOD>;

int main()
{
    int n, d0, max_dist = 0;
    cin >> n;
    map<int, int> d;
    rep(i, n)
    {
        int dist;
        cin >> dist;
        d[dist]++;
        max_dist = max(max_dist, dist);
        if (i == 0)
            d0 = dist;
    }

    if (d0 != 0)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (d[0] > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    else if (d[1] == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    mint ans = 1;
    rep2(i, 2, max_dist + 1)
    {
        ans *= ((mint)d[i - 1]).pow(d[i]);
    }
    cout << ans << endl;
}
