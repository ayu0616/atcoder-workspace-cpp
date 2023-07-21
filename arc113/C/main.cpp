#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    string s;
    cin >> s;

    vvi count = vvi(26, vi(s.size() + 1, 0));
    rep(i, s.size())
    {
        rep(j, 26)
        {
            count[j][i + 1] = count[j][i];
        }
        count[s[i] - 'a'][i + 1]++;
    }

    ll ans = 0;
    pair<char, int> prev = {' ', s.size()};
    for (int i = s.size() - 1; i >= 1; i--)
    {
        if (s[i] == s[i - 1])
        {
            ans += s.size() - i - prev.second * (prev.first == s[i]) - 1 - count[s[i] - 'a'][prev.second] + count[s[i] - 'a'][i + 1];
            prev = {s[i], i};
        }
    }

    cout << ans << endl;
}
