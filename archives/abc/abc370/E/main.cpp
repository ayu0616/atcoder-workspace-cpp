#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    mint all = 0;
    map<ll, mint> mp;
    ll acc = 0;
    all = 1;
    mp[0] = 1;
    rep(i, N) {
        acc += A[i];
        mint cur = all - mp[acc - K];
        all += cur;
        mp[acc] += cur;
        if (i == N - 1) cout << cur << endl;
    }
}
