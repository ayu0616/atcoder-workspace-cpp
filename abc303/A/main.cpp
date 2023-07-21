#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;
    string ans = "Yes";

    rep(i, n)
    {
        if (s[i] == t[i] || s[i] == '0' && t[i] == 'o' || s[i] == 'o' && t[i] == '0' || s[i] == '1' && t[i] == 'l' || s[i] == 'l' && t[i] == '1')
            continue;
        else
        {
            ans = "No";
            break;
        }
    }

    cout << ans << endl;
}
