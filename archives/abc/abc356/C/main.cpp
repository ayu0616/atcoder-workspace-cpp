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
    vvl A(M);
    vector<char> R(M);
    rep(i, M) {
        int c;
        cin >> c;
        A[i].resize(c);
        cin >> A[i];
        cin >> R[i];
    }
    ll ans = 0;
    for (ll S = 0; S < 1 << N; S++) {
        bool ok = true;
        rep(i, M) {
            ll cnt = 0;
            for (auto a : A[i]) {
                if (S >> (a - 1) & 1) {
                    cnt++;
                }
            }
            if (R[i] == 'o' && cnt < K) {
                ok = false;
                break;
            }
            if (R[i] == 'x' && cnt >= K) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << endl;
}
