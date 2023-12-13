#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int grundy(vl &v)
{
    int i = 0;
    while (i < v.size() && v[i] == i)
        ++i;
    if (i == v.size())
        return 0;
    else
        return i;
}

int main()
{
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    ll x = 0;
    for (auto &&i : A)
        x ^= i;
    if (x != 0)
    {
        cout << -1 << endl;
    }
}
