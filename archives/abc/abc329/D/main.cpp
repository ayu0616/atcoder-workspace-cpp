#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N, M;
    cin >> N >> M;
    vi A(M);
    cin >> A;
    vi S(N, 0);
    priority_queue<pii> Q;
    rep(i, M)
    {
        S[A[i] - 1]++;
        Q.push({S[A[i]-1], -A[i]});
        cout << -(Q.top().second) << endl;
    }
}
