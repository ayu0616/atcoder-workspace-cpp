#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    set<int> S;
    rep(i, N)S.insert(A[i]);
    int ma1 = *max_element(all(A));
    S.erase(ma1);
    int ma2 = *max_element(all(S));
    cout << ma2 << endl;
}
