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
    ll N,K;
    cin >> N >> K;
    vl A(N);
    cin >> A;
    set<int> s;
    rep(i, N) { s.insert(A[i]); }
    ll ans = K * (K + 1) / 2;
    ll s_sum = 0;
    for (auto x : s) {
        if(x <= K)
        s_sum += x;
    }
    cout << ans - s_sum << endl;
}
