#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl A(N), B(M);
    cin >> A >> B;
    sort(all(A));
    sort(all(B));
    vl C;
    rep(i, N) C.push_back(A[i]);
    rep(i, M) C.push_back(B[i]);
    sort(all(C));
    rep(i, M + N - 1) {
        auto it = lower_bound(all(A), C[i]);
        if (*it != C[i]) {
            continue;
        }
        if (*(it + 1) == C[i + 1]) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}
