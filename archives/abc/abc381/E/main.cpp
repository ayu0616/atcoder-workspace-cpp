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
    string S;
    cin >> N >> Q >> S;
    vi cnt1(N + 1), cnt2(N + 1);
    rep(i, N) {
        cnt1[i + 1] = cnt1[i] + (S[i] == '1');
        cnt2[i + 1] = cnt2[i] + (S[i] == '2');
    }
    vi slash_idx;
    rep(i, N) {
        if (S[i] == '/') {
            slash_idx.push_back(i);
        }
    }
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        L--;
        const int SL = lower_bound(all(slash_idx), L) - slash_idx.begin();
        const int SR = lower_bound(all(slash_idx), R) - slash_idx.begin();
        if(SL == SR) {
            cout << 0 << endl;
            continue;
        }
        const auto f = [&](int x) { return min(cnt1[slash_idx[x]] - cnt1[L], (cnt2[R] - cnt2[slash_idx[x]])) * 2 + 1; };
        // int sl = SL, sr = SR;
        // while (sr - sl > 100) {
        //     int m = (sl + sr) / 2;
        //     if (f(m) >= f(m - 1)) {
        //         sl = m;
        //     } else {
        //         sr = m;
        //     }
        // }
        int ans = f(SL);
        chmax(ans, f(SR - 1));
        int n = SR - SL;
        for (int i = 0; i < 1000; i++) {
            int j = SL + rand() % n;
            chmax(ans, f(j));
        }
        cout << ans << endl;
    }
}
