#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, M;
    cin >> N >> M;
    vl A(M);
    rep(i, M) cin >> A[i];
    ll current = 0;
    rep(i, 1, N + 1)
    {
        cout << A[current] - i << endl;
        if (i == A[current])
        {
            current++;
        }
    }
}
