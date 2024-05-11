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
    ll N;
    cin >> N;
    vl A(N);
    cin >> A;
    ll ans = accumulate(all(A), 0LL) * (N - 1);
    ll one_e_8 = 100000000;
    sort(all(A));
    ll minus = 0;
    for (ll a : A) {
        auto it = lower_bound(all(A), one_e_8 - a);
        int dist = distance(A.begin(), it);
        dist += (2*a >= one_e_8);
        minus += one_e_8 * (N - dist);
    }
    ans -= minus / 2;
    cout << ans << endl;
}
