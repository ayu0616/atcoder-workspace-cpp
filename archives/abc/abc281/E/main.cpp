#include <numeric>
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
    ll N, M, K;
    cin >> N >> M >> K;
    vl A(N);
    cin >> A;
    vl A_cp = A;
    sort(A.begin(), A.begin() + M);
    multiset<ll> small, big;
    rep(i, M) {
        if (i < K) {
            small.insert(A[i]);
        } else {
            big.insert(A[i]);
        }
    }
    ll tmp = accumulate(A.begin(), A.begin() + K, 0LL);
    vl ans;
    ans.push_back(tmp);
    rep(i, N - M) {
        int j = M + i;
        ll ai = A_cp[i];
        ll aj = A_cp[j];
        if (small.count(ai)) {
            small.erase(small.find(ai));
            tmp -= ai;
        } else {
            big.erase(big.find(ai));
        }
        big.insert(aj);
        while (small.size() < K) {
            ll x = *big.begin();
            big.erase(big.begin());
            small.insert(x);
            tmp += x;
        }
        while (big.size() && *big.begin() < *small.rbegin()) {
            ll x = *big.begin();
            ll y = *small.rbegin();
            big.erase(big.begin());
            small.erase(prev(small.end()));
            big.insert(y);
            small.insert(x);
            tmp += x - y;
        }
        ans.push_back(tmp);
    }
    cout << ans << endl;
}
