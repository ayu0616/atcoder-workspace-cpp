#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n, m, h, k;
    string s;
    cin >> n >> m >> h >> k >> s;
    set<pair<int, int>> items;
    rep(i, m)
    {
        int x, y;
        cin >> x >> y;
        items.insert({x, y});
    }

    string ans = "Yes";
    int pos_x = 0, pos_y = 0;
    rep(i, n)
    {
        if (s[i] == 'U')
        {
            pos_y++;
        }
        else if (s[i] == 'D')
        {
            pos_y--;
        }
        else if (s[i] == 'L')
        {
            pos_x--;
        }
        else if (s[i] == 'R')
        {
            pos_x++;
        }
        h--;
        if (h < 0)
        {
            ans = "No";
            break;
        }
        if (items.find({pos_x, pos_y}) != items.end() && h < k)
        {
            h = k;
            items.erase(items.find({pos_x, pos_y}));
        }
    }

    cout << ans << endl;
}
