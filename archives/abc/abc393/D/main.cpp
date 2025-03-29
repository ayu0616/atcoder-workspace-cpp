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
    string S;
    cin >> N >> S;
    ll M = 0;
    vl sm(N, -1);
    rep(i, N) {
        if (S[i] == '1') {
            sm[i] = M;
            M++;
        }
    }
    ll plus = 0, minus = 0;
    ll cnt = 0;
    multiset<ll> idx;
    rep(i, N) {
        if (S[i] == '1') {
            cnt += i - sm[i] + 1;
            minus++;
            idx.insert(i - sm[i]);
        }
    }
    ll ans = LL_INF;
    rep(i, N - M+1) {
        cnt += (plus - minus);
        chmin(ans, cnt);
        while (!idx.empty() && *idx.begin() == i) {
            idx.erase(idx.begin());
            minus--;
            plus++;
        }
    }
    cout << ans << endl;
}
