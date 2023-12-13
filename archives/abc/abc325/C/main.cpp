#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    vvl visited(H, vl(W, 0));
    rep(i, H) cin >> S[i];
    UnionFind uf(H * W);
    ll not_cnt = 0;
    rep(i, H) rep(j, W)
    {
        char s = S[i][j];
        if (s != '#')
        {
            not_cnt++;
            continue;
        }
        rep(k, 8)
        {
            int dx = dx8[k], dy = dy8[k];
            if (i + dx < 0 || i + dx >= H || j + dy < 0 || j + dy >= W)
                continue;
            if (S[i + dx][j + dy] == '#')
                uf.unite(i * W + j, (i + dx) * W + (j + dy));
        }
    }
    cout << uf.groups() - not_cnt << endl;
}
