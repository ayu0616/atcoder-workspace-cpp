#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int n;
string s;

int main()
{
    cin >> n >> s;
    int ans = -1, tmp = 0;
    char prev = s[0];
    if (prev == 'o')
        tmp++;
    for (int i = 1; i < n; i++)
    {
        if (prev == '-' && s[i] == 'o')
        {
            tmp = 1;
        }
        else if (prev == 'o' && s[i] == '-')
        {
            ans = max(ans, tmp);
            tmp = 0;
        }
        else if (prev == 'o' && s[i] == 'o')
        {
            tmp++;
        }
        prev = s[i];
    }
    if (prev == 'o')
        ans = max(ans, tmp);
    if (ans == 0 || ans == n)
        ans = -1;
    cout << ans << endl;
}
