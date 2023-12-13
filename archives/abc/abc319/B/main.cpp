#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N;
    cin >> N;
    vector<char> ans(N + 1, '-');
    rep(i, N + 1)
    {
        rep2(j, 1, 10)
        {
            if (N % j != 0)
                continue;
            if (i % ((int)(N / j)) == 0)
            {
                ans[i] = '0' + j;
                break;
            }
        }
    }
    rep(i, N + 1)
    {
        cout << ans[i];
    }
    cout << endl;
}
