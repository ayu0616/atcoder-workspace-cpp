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
    vvpll nums(N);
    map<ll, ll> e_max;
    map<pll, ll> p_e_count;
    rep(i, N) {
        ll m;
        cin >> m;
        rep(j, m) {
            ll p, e;
            cin >> p >> e;
            nums[i].emplace_back(p, e);
            e_max[p] = max(e_max[p], e);
            p_e_count[{p, e}]++;
        }
    }
    int c = 0;
    rep(i, N) {
        for (auto [p, e] : nums[i]) {
            if (e_max[p] == e && p_e_count[{p, e}] == 1) {
                c++;
                break;
            }
        }
    }
    cout << min(c + 1, N) << endl;
}
