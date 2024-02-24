#include <algorithm>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N;
    cin >> N;
    vl A(N);
    cin >> A;
    int Q;
    cin >> Q;

    map<int, tuple<ll, ll, ll>> memo;
    map<int, SegTree> memo_seg;
    set<int> memo_idx;
    SegTree seg(N);
    int ok_seg_idx = 0;
    seg.update(0, N, 0);
    rep(j, Q) {
        int typ;
        cin >> typ;
        switch (typ) {
            case 1: {
                ll l, r, x;
                cin >> l >> r >> x;
                l--;
                memo[j] = {l, r, x};
                memo_idx.insert(j);
                break;
            }
            case 2: {
                int i;
                cin >> i;
                i--;
                memo_idx.erase(i);
                ok_seg_idx = *memo_idx.lower_bound(i);
                break;
            }
            case 3: {
                int i;
                cin >> i;
                i--;
                ll ans = A[i];
                auto it = memo_idx.lower_bound(ok_seg_idx);
                seg = memo_seg[ok_seg_idx];
                while (it != memo_idx.end()) {
                    auto idx = *it;
                    auto [l, r, x] = memo[idx];
                    seg.update(l, r, -x);
                    memo_seg[idx] = seg;
                    it++;
                }
                ok_seg_idx = *memo_idx.rbegin();
                chmax(ans, -seg.query(i, i + 1));
                cout << ans << endl;
                break;
            }
        }
    }
}
