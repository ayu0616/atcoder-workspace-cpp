#include <algorithm>
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
    ll N, M;
    cin >> N >> M;
    vl A(N), B(M);
    cin >> A >> B;
    sort(all(A)), sort(all(B));
    ll l = 0, r = LL_INF;
    while (r - l > 1) {
        ll x = (l + r) / 2;
        ll a_cnt = upper_bound(all(A), x) - A.begin();
        ll b_cnt = B.end() - lower_bound(all(B), x);
        if (a_cnt >= b_cnt) {
            r = x;
        } else {
            l = x;
        }
    }
    cout << r << endl;
}
