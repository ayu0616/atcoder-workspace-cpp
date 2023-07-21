#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    string s;
    cin >> n >> s;
    string ans = "out";
    bool f = false;
    for (auto c : s)
    {
        if (c == '|')
            f = !f;
        else if (f && c == '*')
        {
            ans = "in";
        }
    }
    cout << ans << endl;
}
