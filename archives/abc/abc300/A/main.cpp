#include "../../lib.hpp"

// #define MOD 1000000007
// #define MOD 998244353

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    rep(i, n)
    {
        int c;
        cin >> c;
        if (a + b == c)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
