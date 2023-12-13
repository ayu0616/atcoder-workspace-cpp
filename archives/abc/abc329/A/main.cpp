#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    string S;
    cin >> S;
    rep(i, S.size())
    {
        cout << S[i] << " \n"[i == S.size() - 1];
    }
}
