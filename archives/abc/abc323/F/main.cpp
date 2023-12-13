#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll XA, YA, XB, YB, XC, YC;
    cin >> XA >> YA >> XB >> YB >> XC >> YC;
    ll ans1 = 1e18;
    ll delta[2] = {1, -1};
    ll mx, my;
    rep(i, 2) rep(j, 2)
    {
        if (abs(XA - XB + delta[i]) + abs(YA - YB + delta[j]) < ans1)
        {
            mx = XA - XB + delta[i];
            my = YA - YB + delta[j];
            ans1 = abs(XA - XB + delta[i]) + abs(YA - YB + delta[j]);
        }
    }
}
