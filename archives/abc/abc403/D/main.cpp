#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, D;
    cin >> N >> D;
    vl A(N);
    cin >> A;
    set<ll> S(A.begin(), A.end());
    multiset<ll> ms(A.begin(), A.end());

    vb done(N, false);
    ll ans = 0;
    for (auto a : S) {
        if (done[a]) {
            continue;
        }
        vi v;
        v.push_back(a);
        while (true) {
            auto it = S.find(v.back() + D);
            if (it == S.end()) {
                break;
            }
            v.push_back(*it);
        }
        for (auto vi : v) {
            done[vi] = true;
        }
        if (v.size() <= 1) {
            continue;
        }
        ll even = 0, odd = 0;
        rep(i, v.size()) {
            if (i % 2 == 0) {
                even += ms.count(v[i]);
            } else {
                odd += ms.count(v[i]);
            }
        }
        ans += min(even, odd);
    }
    cout << ans << endl;
}
