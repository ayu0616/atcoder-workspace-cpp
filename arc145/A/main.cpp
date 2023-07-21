#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string ans = "Yes";
    if((s[0]=='A' && s[n-1]=='B')||s=="BA"){
        ans = "No";
    }
    cout << ans << endl;
}
