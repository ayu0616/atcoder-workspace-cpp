#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ax, ay;
    rep(i, n)
    {
        int a;
        cin >> a;
        if (i % 2 == 0)
            ax.push_back(a);
        else
            ay.push_back(a);
    }
    vector<bool> dpx(20001, false), dpy(20001, false);
    dpx[10000] = true;
    dpx[10000 + ax[0]] = true;
    ax = vector<int>(ax.begin() + 1, ax.end());
    rep(i, ax.size())
    {
        vector<bool> nxtdp(20001, false);
        rep(j, 20001)
        {
            if (dpx[j])
            {
                if (j + ax[i] <= 20000)
                    nxtdp[j + ax[i]] = true;
                if (j - ax[i] >= 0)
                    nxtdp[j - ax[i]] = true;
            }
        }
        dpx = nxtdp;
    }
    dpy[10000] = true;
    rep(i, ay.size())
    {
        vector<bool> nxtdp(20001, false);
        rep(j, 20001)
        {
            if (dpy[j])
            {
                if (j + ay[i] <= 20000)
                    nxtdp[j + ay[i]] = true;
                if (j - ay[i] >= 0)
                    nxtdp[j - ay[i]] = true;
            }
        }
        dpy = nxtdp;
    }
    bool ans = dpx[10000 + x] && dpy[10000 + y];
    cout << (ans ? "Yes" : "No") << endl;
}
