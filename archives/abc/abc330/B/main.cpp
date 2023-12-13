#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, L, R;
    cin >> N >> L >> R;
    vl A(N);
    cin >> A;
    vl ans(N);
    rep(i, N)
    {
        if (L <= A[i] && A[i] <= R)
            ans[i] = A[i];
        else
        {
            if (abs(L - A[i]) < abs(R - A[i]))
                ans[i] = L;
            else
                ans[i] = R;
        }
    }
    cout << ans << endl;
}
