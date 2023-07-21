#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int n;
vector<string> s;

bool is_kaibun(string s)
{
    int n = s.size();
    rep(i, n / 2)
    {
        if (s[i] != s[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    cin >> n;
    s.resize(n);
    rep(i, n) cin >> s[i];
    string ans = "No";
    rep(i, n) rep(j, n)
    {
        if (i == j)
            continue;
        if (is_kaibun(s[i] + s[j]))
            ans = "Yes";
    }
    cout << ans << endl;
}
