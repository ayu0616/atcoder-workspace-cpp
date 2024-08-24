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
    vi A(N);
    cin >> A;
    int cnt = 0;
    sort(all(A));
    reverse(all(A));
    while (A[1] != 0) {
        A[0]--, A[1]--;
        sort(all(A));
        reverse(all(A));
        cnt++;
    }
    cout << cnt << endl;
}
