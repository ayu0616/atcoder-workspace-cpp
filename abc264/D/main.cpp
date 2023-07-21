#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

string s;
string atcoder = "atcoder";
int ans = 0;

int main()
{
    cin >> s;
    rep(i, 7)
    {
        int pos = 0;
        rep(j, s.size())
        {
            if (s[j] == atcoder[i])
            {
                pos = j;
                break;
            }
        }
        // cout << s << " " << pos << " " << atcoder[i] << endl;
        ans += pos - i;
        string tmp = "";
        for (int j = 0; j < i; j++)
        {
            tmp += s[j];
        }
        tmp += atcoder[i];
        for (int j = i; j < 7; j++)
        {
            if (j != pos)
                tmp += s[j];
        }
        s = tmp;
    }
    cout << ans << endl;
}
