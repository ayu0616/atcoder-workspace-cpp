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
    ll N, T;
    string S;
    cin >> N >> T >> S;
    vl X(N);
    cin >> X;
    vl v0, v1;
    rep(i, N) {
        if (S[i] == '0')
            v0.push_back(X[i]);
        else
            v1.push_back(X[i]);
    }
    sort(all(v0));
    sort(all(v1));
    ll ans = 0;
    for (auto x : v1) {
        auto r_it = upper_bound(all(v0), x + 2 * T);
        auto l_it = lower_bound(all(v0), x);
        ans += r_it - l_it;
    }
    cout << ans << endl;
}
