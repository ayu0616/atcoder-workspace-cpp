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
    ll N, T;
    cin >> N >> T;
    vl A(T);
    cin >> A;
    rep(i, T) A[i]--;
    vl rows(N, 0), cols(N, 0), cross(2, 0);
    int ans = 0;
    for (ll a : A) {
        ans++;
        ll i = a / N;
        ll j = a % N;
        rows[i]++;
        cols[j]++;
        if (i == j) {
            cross[0]++;
        }
        if (i + j == N - 1) {
            cross[1]++;
        }
        if (rows[i] == N || cols[j] == N || cross[0] == N || cross[1] == N) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
