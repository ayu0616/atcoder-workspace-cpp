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
    vi C(N), A(N);
    C[0] = -1;
    rep(i, N - 1) { cin >> C[i + 1]; }
    A[0] = 0;
    rep(i, N - 1) { cin >> A[i + 1]; }
    int ans = 0;
    for (int i = N - 1; i > 0; i--) {
        if (A[i] == 0) {
            continue;
        }
        ans++;
        int val = N, min_j = N;
        bool ok = false;
        for (int j = i - C[i]; j < i; j++) {
            if (j == 0 || A[j] > 0) {
                A[j] += A[i];
                A[i] = 0;
                ok = true;
                break;
            }
            if (A[j] == 0) {
                if (chmin(val, j - C[j])) {
                    min_j = j;
                }
            }
        }
        if(!ok){
            A[min_j] += A[i];
            A[i] = 0;
        }
    }
    cout << ans << endl;
}
