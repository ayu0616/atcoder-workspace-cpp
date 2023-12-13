#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    cin >> N >> M;
    vl L(N);
    rep(i, N)
    {
        cin >> L[i];
        L[i]++;
    }

    ll mi = *max_element(all(L)) - 1;
    ll ma = accumulate(all(L), 0LL);

    while (mi + 1 < ma)
    {
        ll md = (mi + ma) / 2;
        int rows = 1;
        ll length = 0;
        rep(i, N)
        {
            length += L[i];
            if (length > md)
            {
                length = L[i];
                rows++;
            }
        }

        if (rows > M)
        {
            mi = md;
        }
        else
        {
            ma = md;
        }
    }

    cout << mi << endl;
}
