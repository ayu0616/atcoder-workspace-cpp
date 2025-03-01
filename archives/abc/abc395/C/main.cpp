#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

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
    map<int, vi> mp;
    rep(i, N) { mp[A[i]].push_back(i); }
    int ans = INT_INF;
    for (auto [k, v] : mp) {
        rep(i, v.size() - 1) { ans = min(ans, v[i + 1] - v[i] + 1); }
    }
    if (ans == INT_INF) ans = -1;
    cout << ans << endl;
}
