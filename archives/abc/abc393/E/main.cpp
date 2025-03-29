#include <algorithm>
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

vl divisor(ll n) {
    vl ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    map<ll, ll> cnt;
    vvl g(N);
    rep(i, N) {
        vl d = divisor(A[i]);
        g[i] = d;
        for (auto v : d) {
            cnt[v]++;
        }
    }
    rep(i, N) {
        int m = 0;
        rep(j, g[i].size()) {
            if (cnt[g[i][j]] >= K) {
                m = j;
            }
        }
        ll ans = g[i][m];
        cout << ans << endl;
    }
}
