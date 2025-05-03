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
    map<ll, ll> cnt, num;
    rep(i, N) { cnt[A[i]]++; num[A[i]] = i+1; }
    sort(all(A));
    reverse(all(A));
    for (auto a : A) {
        if (cnt[a] == 1) {
            cout << num[a] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
