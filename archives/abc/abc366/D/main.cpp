#include <numeric>
#include <vector>
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
    vector<vvi> A(N, vvi(N, vi(N)));
    cin >> A;
    vector<vvi> A_sum(N, vvi(N + 1, vi(N + 1)));
    rep(i, N) {
        vvi a = A[i];
        vvi a_sum = vvi(N + 1, vi(N + 1));
        rep(j, N) {
            rep(k, N) { a_sum[j + 1][k + 1] = a_sum[j][k + 1] + a_sum[j + 1][k] - a_sum[j][k] + a[j][k]; }
        }
        A_sum[i] = a_sum;
    }

    int Q;
    cin >> Q;
    while (Q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;
        --lx, --ly, --lz;
        ll ans = 0;
        for (int x = lx; x < rx; ++x) {
            ans += A_sum[x][ry][rz] - A_sum[x][ly][rz] - A_sum[x][ry][lz] + A_sum[x][ly][lz];
        }
        cout << ans << endl;
    }
}
