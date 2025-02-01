#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, W;
    cin >> N >> W;
    vl X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        X[i]--, Y[i]--;
    }
    vector<vector<pll>> B(W);
    rep(i, N) { B[X[i]].push_back({Y[i], i}); }
    rep(i, W) {
        sort(all(B[i]));
        reverse(all(B[i]));
    }
    vl T(N, LL_INF);
    bool ok = true;
    while (ok) {
        ll max_y = 0;
        vi idx;
        rep(i, W) {
            if (B[i].empty()) {
                ok = false;
                break;
            }
            auto [y, j] = B[i].back();
            B[i].pop_back();
            chmax(max_y, y);
            idx.push_back(j);
        }
        if (ok) {
            for (auto j : idx) {
                T[j] = max_y;
            }
        }
    }
    int Q;
    cin >> Q;
    while (Q--) {
        ll t, A;
        cin >> t >> A;
        A--;
        yes_no(T[A] >= t);
    }
}
