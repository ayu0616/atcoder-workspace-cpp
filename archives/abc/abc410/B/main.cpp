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
    ll N, Q;
    cin >> N >> Q;
    vl X(Q);
    cin >> X;
    vl box(N), ans(Q);
    rep(i, Q) {
        if (X[i] == 0) {
            int minval = INT_INF;
            int mini = -1;
            rep(j, N) {
                if (minval > box[j]) {
                    minval = box[j];
                    mini = j;
                }
            }
            ans[i] = mini + 1;
            box[mini]++;

        } else {
            box[X[i] - 1]++;
            ans[i] = X[i];
        }
    }

    cout << ans << endl;
}
