#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin >> N;
    string s = to_string(N);
    ll x = s[2] - '0';
    ll y = s[1] - '0';
    ll z = s[0] - '0';
    while (y * z != x)
    {
        N++;
        s = to_string(N);
        x = s[2] - '0';
        y = s[1] - '0';
        z = s[0] - '0';
    }
    cout << N << endl;
}
