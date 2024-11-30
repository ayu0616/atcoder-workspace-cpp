#include <algorithm>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl A(N), B(M);
    cin >> A >> B;
    vl Amin(N + 1, LL_INF);
    rep(i, N) { Amin[i + 1] = min(Amin[i], A[i]); }
    rep(i, N+1) {Amin[i] = -Amin[i];}
    rep(i, M) {
        ll b = -B[i];
        if (b > Amin.back()) {
            cout << -1 << endl;
            continue;
        }
        ll idx = lower_bound(all(Amin), b) - Amin.begin();
        cout << idx << endl;
    }
}
