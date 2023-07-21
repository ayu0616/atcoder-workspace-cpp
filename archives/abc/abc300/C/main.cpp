#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353
int h, w;
vector<string> c;

int cross(int i, int j)
{
    if (c[i][j] == '.')
        return 0;
    int siz[] = {0, 0, 0, 0};
    int nowi = i - 1, nowj = j - 1;
    while (nowi >= 0 && nowj >= 0 && c[nowi][nowj] == '#')
    {
        siz[0]++;
        nowi--;
        nowj--;
    }
    nowi = i - 1, nowj = j + 1;
    while (nowi >= 0 && nowj < w && c[nowi][nowj] == '#')
    {
        siz[1]++;
        nowi--;
        nowj++;
    }
    nowi = i + 1, nowj = j - 1;
    while (nowi < h && nowj >= 0 && c[nowi][nowj] == '#')
    {
        siz[2]++;
        nowi++;
        nowj--;
    }
    nowi = i + 1, nowj = j + 1;
    while (nowi < h && nowj < w && c[nowi][nowj] == '#')
    {
        siz[3]++;
        nowi++;
        nowj++;
    }
    int res = 1e9;
    rep(i, 4) res = min(res, siz[i]);
    return res;
}

int main()
{
    cin >> h >> w;
    c.resize(h);
    rep(i, h) { cin >> c[i]; }
    int n = min(h, w);
    int ans[n + 1];
    rep(i, n + 1) { ans[i] = 0; }
    rep(i, h) rep(j, w)
    {
        ans[cross(i, j)]++;
    }
    rep(i, n) cout << ans[i + 1] << (i == n - 1 ? "\n" : " ");
}
