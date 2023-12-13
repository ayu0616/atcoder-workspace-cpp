#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, prev, now;
    cin >> N >> prev;
    rep(i, N - 1)
    {
        cin >> now;
        if (prev != now)
        {
            cout << "No" << endl;
            return 0;
        }
        prev = now;
    }
    if (prev != now)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}
