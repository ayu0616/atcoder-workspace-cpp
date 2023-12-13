#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    string S;
    cin >> N >> S;
    rep(i, N - 1)
    {
        if (S[i] == 'a' && S[i + 1] == 'b' || S[i] == 'b' && S[i + 1] == 'a')
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
