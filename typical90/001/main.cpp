#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, L, K;
    cin >> N >> L >> K;
    vector<int> A(N);
    cin >> A;
    A.push_back(L);
    int l = 1, r = L+1, mid;

    while (r - l > 1) {
        mid = (l + r) / 2;
        int prev = 0, cnt = 0;
        rep(i, N + 1) {
            int cur = A[i];
            if (cur - prev >= mid) {
                cnt++;
                prev = A[i];
            }
        }
        if (cnt < K + 1) {
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << l << endl;
}
