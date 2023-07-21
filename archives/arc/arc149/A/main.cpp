#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m;
    cin >> n >> m;
    vvl mods(n + 1, vl(10, 0));
    pair<int, int> p = {-1, -1};

    rep2(i, 1, n + 1)
    {
        rep2(j, 1, 10)
        {
            mods[i][j] = (10 * mods[i - 1][j] + j) % m;
            if (mods[i][j] == 0)
            {
                p = {i, j};
            }
        }
    }

    if (p.first == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    else
    {
        rep(i, p.first)
        {
            cout << p.second;
        }
        cout << endl;
    }
}
