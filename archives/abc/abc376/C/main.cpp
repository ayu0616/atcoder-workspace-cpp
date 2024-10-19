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
    ll N;
    cin >> N;
    vl A(N), B(N - 1);
    cin >> A >> B;
    sort(all(A)), sort(all(B));
    reverse(all(A)), reverse(all(B));
    int s = 0;
    int ans = 0;
    rep(i, N ) {
        if (A[i] <= B[i-s]) {
        } else if(s==0) {
            s += 1;
            ans = A[i];
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
