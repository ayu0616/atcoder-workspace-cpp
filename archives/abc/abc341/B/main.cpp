#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N;
    cin >> N;
    vl A(N), S(N - 1), T(N - 1);
    cin >> A;
    rep(i, N - 1) {
        cin >> S[i] >> T[i];
    }
    rep(i, N - 1) { A[i + 1] += (ll)(A[i] / S[i]) * T[i]; }
    cout<<A[N-1]<<endl;
}
