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
    vl X(M), A(M);
    cin >> X >> A;
    rep(i, M) X[i]--;
    if (X[0].first != 0) {
        cout << -1 << endl;
        return 0;
    }
    vpll XA(M);
    rep(i, M) XA[i] = {X[i], A[i]};
    sort(all(XA));
    ll ans = 0;
    ll filled = 0;
    vpll cur;
    cur.emplace_back(XA[0]);
    rep(i, 1, N) {
        auto [x, a] = XA[i];
        int M = cur.size();
        rep(i, M) {
            int idx = M - 1 - i;
            auto [cx, ca] = cur[idx];
            filled = min(x, cx + ca - 1);
        }
        cur.emplace_back(XA[i]);
    }
}
