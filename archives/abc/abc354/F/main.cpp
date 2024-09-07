#include <algorithm>
#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vi lis(const vl &A) {
    int N = A.size();
    vl dp(N, LL_INF);
    vi ret(N, 0);
    rep(i, N) {
        auto it = lower_bound(all(dp), A[i]);
        *it = A[i];
        ret[i] = it - dp.begin() + 1;
    }
    return ret;
}

int main() {
    cout << fixed << setprecision(18);
    ll T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        vl A(N);
        cin >> A;
        vi lis_front = lis(A);
        reverse(all(A));
        rep(i, N) { A[i] = -A[i]; }
        vi lis_back = lis(A);
        rep(i, N) { A[i] = -A[i]; }
        reverse(all(lis_back));
        const int lis_len = *max_element(all(lis_front));
        vi ans;
        rep(i, N) {
            if (lis_front[i] + lis_back[i] - 1 == lis_len) {
                ans.push_back(i+1);
            }
        }
        cout << ans.size() << endl;
        cout << ans << endl;
    }
}
