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
    set<ll> s1, s2;
    multiset<ll> m1, m2;
    rep(i, N) {
        s2.insert(A[i]);
        m2.insert(A[i]);
    }
    int ans = 0;
    rep(i, N) {
        m2.erase(m2.find(A[i]));
        m1.insert(A[i]);
        if (m2.count(A[i]) == 0) {
            s2.erase(s2.find(A[i]));
        }
        s1.insert(A[i]);
        ans = max(ans, (int)(s1.size() + s2.size()));
    }
    cout << ans << endl;
}
