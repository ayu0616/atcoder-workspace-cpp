#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

bool is_kaibun(string s)
{
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}

int main()
{
    string S;
    cin >> S;

    ll ans = 0;
    rep(i, S.size()) rep(j, S.size())
    {
        string s = S.substr(i, j - i + 1);
        if (is_kaibun(s))
        {
            ans = max(ans, (ll)s.size());
        }
    }
    cout << ans << endl;
}
