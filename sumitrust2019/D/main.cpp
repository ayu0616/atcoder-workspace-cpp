#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;
    rep(i, 10) rep(j, 10) rep(k, 10)
    {
        int a = s.find(i + '0');
        int b = s.find(j + '0', a + 1);
        int c = s.find(k + '0', b + 1);
        if (a != string::npos && b != string::npos && c != string::npos)
            ans++;
    }
    cout << ans << endl;
}
