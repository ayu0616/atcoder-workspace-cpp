#include <algorithm>

#include "hassaku/prime.hpp"
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vl primes;

bool is_ok(ll N) {
    ll cnt = 0;
    if (N % 2 == 0) {
        cnt++;
    }
    while (N % 2 == 0) {
        N /= 2;
    }
    for (auto p : primes) {
        if (p * p > N) break;
        if (N % p == 0) {
            cnt++;
            while (N % p == 0) {
                N /= p;
            }
            if (N == 1) break;
        }
    }
    if (N > 1) cnt++;
    return cnt == 2;
}

int main() {
    cout << fixed << setprecision(18);
    ll Q;
    cin >> Q;
    primes = hassaku::create_primes(1e6);
    vl li;
    for (ll i = 1; i <= 1e6; i++) {
        if (is_ok(i)) {
            li.push_back(i * i);
        }
    }
    while (Q--) {
        ll A;
        cin >> A;
        ll ok = 0, ng = li.size();
        while (ng - ok > 1) {
            ll mid = (ok + ng) / 2;
            if (li[mid] <= A) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        cout << li[ok] << endl;
    }
}
