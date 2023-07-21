#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int h, w, adot = 0, bdot = 0, ahash = 0, bhash = 0;
    cin >> h >> w;
    vector<string> a(h), b(h);
    rep(i, h) { cin >> a[i]; }
    rep(i, h) { cin >> b[i]; }
    string ans = "No";
    rep(i, h) rep(j, w)
    {
        bool ok = true;
        rep(mi, h) rep(mj, w)
        {
            if (a[(i + mi) % h][(j + mj) % w] != b[mi][mj])
                ok = false;
        }
        if (ok)
            ans = "Yes";
    }
    cout << ans << endl;
}
