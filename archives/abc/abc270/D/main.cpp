#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N, K;
vl A;

vl memo(10000 + 10, -1);
ll solve(ll n) {
    if (memo[n] != -1) return memo[n];
    ll res = 0;
    rep(i, K) {
        if(n - A[i] < 0) continue;
        chmax(res, A[i] + (n - A[i]) - solve(n - A[i]));
    }
    return memo[n] = res;
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> K;
    A.resize(N);
    cin >> A;
    memo[0] = 0;
    ll res = solve(N);
    cout << res << endl;
}
