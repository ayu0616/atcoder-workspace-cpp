#include <cassert>
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
    vl A(N);
    cin >> A;
    int ans = 0;
    int l = -1;
    map<ll, int> mp;
    auto solve = [&](int i) {
        int j = i + 1;
        if (A[i] == A[j]) {
            if (l == -1) {
                l = i;
            }
            assert(l != -1);
            if (mp.count(A[i]) && mp[A[i]] >= l) {
                l = mp[A[i]] + 2;
            }
            mp[A[i]] = i;
            chmax(ans, j - l + 1);
            assert(ans % 2 == 0);
        } else {
            l = -1;
        }
    };
    for (int i = 0; i < N - 1; i += 2) {
        solve(i);
    }

    mp.clear();
    l = -1;

    for (int i = 1; i < N - 1; i += 2) {
        solve(i);
    }
    cout << ans << endl;
}
