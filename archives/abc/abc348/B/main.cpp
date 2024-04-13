#include <cmath>
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
    int N;
    cin >> N;
    vi X(N), Y(N);
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, N) {
        int x = X[i], y = Y[i];
        int max_dist = 0;
        int max_idx = -1;
        rep(j, N) {
            if (i == j) continue;
            int xx = X[j], yy = Y[j];
            int dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);
            if (dist > max_dist) {
                max_dist = dist;
                max_idx = j;
            }
        }
        cout << max_idx + 1 << endl;
    }
}
