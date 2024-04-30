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
    ll N, Q;
    cin >> N >> Q;
    vs P(N);
    cin >> P;
    vvl cnt(N + 1, vl(N + 1));
    rep(i, N) {
        rep(j, N) { cnt[i + 1][j + 1] = cnt[i + 1][j] + cnt[i][j + 1] - cnt[i][j] + (P[i][j] == 'B'); }
    }
    function<ll(ll, ll)> g = [&](ll H, ll W) {
        if (H <= N && W <= N) return cnt[H][W];
        ll Hq = H / N, Hr = H % N, Wq = W / N, Wr = W % N;
        ll res = 0;
        res += g(N, N) * (Hq * Wq);
        res += g(N, Wr) * Hq;
        res += g(Hr, N) * Wq;
        res += g(Hr, Wr);
        return res;
    };
    while (Q--) {
        ll A, B, C, D;
        cin >> A >> B >> C >> D;
        C++, D++;
        ll res = g(C, D) - g(A, D) - g(C, B) + g(A, B);
        cout << res << endl;
    }
}
