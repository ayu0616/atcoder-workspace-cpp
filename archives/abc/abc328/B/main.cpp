#ifdef HASSAKU_DEBUG
#define _GLIBCXX_DEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N;
    cin >> N;
    vi D(N);
    cin >> D;
    int ans = 0;
    rep(i, N)
    {
        int m = i + 1;
        if (m < 10)
        {
            if (m <= D[i])
                ans++;
            if (m * 11 <= D[i])
                ans++;
        }
        else
        {
            if (m % 11 == 0)
            {
                if (m / 11 <= D[i])
                    ans++;
                if (m <= D[i])
                    ans++;
            }
        }
    }
    cout << ans << endl;
}
