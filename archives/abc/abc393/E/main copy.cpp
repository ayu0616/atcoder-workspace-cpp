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

vector<ll> get_primes() {
    constexpr ll N = 1000000;
    vb is_prime(N + 1, true);
    rep(i, 2, N + 1) {
        if (is_prime[i]) {
            for (int n = i * 2; n <= N; n += i) {
                is_prime[n] = false;
            }
        }
    }
    vl ret;
    rep(i, 2, N + 1) {
        if (is_prime[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    const vl primes = get_primes();
    map<ll, multiset<ll>> p_cnt;
    rep(i, N) {
        if (binary_search(all(primes), A[i])) {
            p_cnt[A[i]].insert(1);
        }
        ll n = A[i];
        for (auto p : primes) {
            if (n % p == 0) {
                int c = 0;
                while(n%p==0){
                    c++;
                    n/=p;
                }
                p_cnt[p].insert(c);
            }
            if(n==1)break;
        }
    }
    debug(*p_cnt[1].begin());
}
