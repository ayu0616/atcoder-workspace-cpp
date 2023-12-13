#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    string S;
    cin >> S;
    string ans = "Yes";
    for (int i = 1; i < 16; i += 2)
    {
        if (S[i] == '1')
            ans = "No";
    }
    cout << ans << endl;
}
