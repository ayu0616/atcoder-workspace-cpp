#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl P(N);
    cin >> P;
    ll k = 0;
    vl cnt;
    cnt.push_back(0);
    rep(i, 0, N - 1) {
        if (P[i] < P[i + 1]) {
            cnt[k]++;
        } else if (P[i] > P[i + 1]) {
            if (cnt[k] != 0) {
                cnt.push_back(0);
                k++;
            }
        } else {
            if (cnt[k] != 0) {
                cnt.push_back(0);
                k++;
            }
        }
    }
    ll ans = 0;
    rep(i, cnt.size() - 1) { ans += cnt[i] * cnt[i + 1]; }
    cout << ans << endl;
}
