#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, Q;
    cin >> N;
    vi A(N);
    cin >> A;
    cin >> Q;

    sort(all(A));
    while (Q--) {
        int B;
        cin >> B;
        auto it = lower_bound(all(A), B);
        int ans = abs(B - *it);
        if (it != A.begin()) {
            it--;
            chmin(ans, abs(B - *(it)));
        }
        cout << ans << endl;
    }
}
