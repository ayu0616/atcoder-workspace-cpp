#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

vi s(8);

int main()
{
    rep(i, 8) { cin >> s[i]; }
    rep(i, 8)
    {
        if (i < 7 && s[i] > s[i + 1])
        {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] < 100 || s[i] > 675)
        {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] % 25 != 0)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
