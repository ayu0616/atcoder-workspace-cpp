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
    vi slash_idx;
    rep(i, N) {
        if (S[i] == '/') slash_idx.push_back(i + 1);
    }
    vi one_cnt(N + 1), two_cnt(N + 1);
    rep(i, N) {
        one_cnt[i + 1] = one_cnt[i] + (S[i] == '1');
        two_cnt[i + 1] = two_cnt[i] + (S[i] == '2');
    }
    while (Q--) {
        ll L, R;
        cin >> L >> R;
        int l = lower_bound(all(slash_idx), L) - slash_idx.begin();
        int r = lower_bound(all(slash_idx), R + 1) - slash_idx.begin();
        if (l == r) {
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int i = slash_idx[mid];
            int one = one_cnt[i] - one_cnt[L - 1];
            int two = two_cnt[R] - two_cnt[i];
            res = max(res, min(one, two) * 2 + 1);
            if (one > two) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << res << endl;
    }
}
