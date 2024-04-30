#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N;
    cin >> N;
    vi A(N);
    cin >> A;
    auto A_cp = A;
    sort(all(A_cp));
    reverse(all(A_cp));
    map<int, int> cnt;
    map<int, int> sum;
    rep(i, N) cnt[A_cp[i]]++;
    int prev = -1;
    rep(i, N) {
        if (i == 0) {
            prev = A_cp[i];
            continue;
        }
        if (prev == A_cp[i]) continue;
        sum[A_cp[i]] = sum[prev] + prev * cnt[prev];
        prev = A_cp[i];
    }
    vi ans(N);
    rep(i, N) { ans[i] = sum[A[i]]; }
    // vi A_sum(N + 1, 0);
    // rep(i, N) A_sum[i + 1] = A_sum[i] + A_cp[i];
    // map<int, int> mp;
    // rep(i, N) { mp[A[i]] = upper_bound(all(A_cp), A[i]) - A_cp.begin(); }
    // vi ans(N);
    // rep(i, N) { ans[i] = A_sum.back() - A_sum[mp[A[i]]]; }
    cout << ans << endl;
}
