#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    string S, T;
    cin >> N >> M >> S >> T;

    if (T.substr(0, N) == S && T.substr(M - N, N) == S)
    {
        cout << 0 << endl;
    }
    else if (T.substr(0, N) == S)
    {
        cout << 1 << endl;
    }
    else if (T.substr(M - N, N) == S)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }
}
