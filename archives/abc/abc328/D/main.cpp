#ifdef HASSAKU_DEBUG
#define _GLIBCXX_DEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

constexpr string ABC = "ABC";

int main()
{
    string S;
    cin >> S;
    ll idx = 0;
    while (idx + 2 < S.size())
    {
        if (S.substr(idx, 3) == ABC)
        {
            S = S.substr(0, idx) + S.substr(idx + 3);
            idx = max(0, idx - 2);
        }
        else
        {
            idx++;
        }
    }
    cout << S << endl;
}
