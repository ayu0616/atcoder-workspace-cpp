#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;
int h, w;
vector<string> s;

int search(int i, int j)
{
    if (i < 0 || i >= h || j < 0 || j >= w)
        return 0;
    if (s[i][j] == '#')
        return 1;
    return 0;
}

int main()
{
    cin >> h >> w;
    s.resize(h);
    rep(i, h) cin >> s[i];
    rep(i, h) rep(j, w)
    {
        int cnt = 0;
        for (int di = -1; di <= 1; di++)
            for (int dj = -1; dj <= 1; dj++)
            {
                if (di != 0 && dj != 0)
                {
                    continue;
                }
                cnt += search(i + di, j + dj);
            }
        if (s[i][j] == '.' && cnt>=2){
            cout<<i+1<<" "<<j+1<<endl;
            return 0;
        }
    }
}
