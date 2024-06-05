#include <algorithm>
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
    ll H, W, rs, cs, N, Q;
    cin >> H >> W >> rs >> cs >> N;
    rs--;
    cs--;
    map<ll, vector<ll>> row_wall, col_wall;
    rep(i, N) {
        ll r, c;
        cin >> r >> c;
        r--;
        c--;
        row_wall[r].push_back(c);
        col_wall[c].push_back(r);
    }
    for (auto& [k, v] : row_wall) { sort(all(v)); }
    for (auto& [k, v] : col_wall) { sort(all(v)); }
    cin >> Q;
    rep(i, Q) {
        char d;
        ll l;
        cin >> d >> l;
        switch (d) {
            case 'L': {
                ll dist = max(0LL, cs - l);
                if (row_wall[rs].empty()) {
                    cs = dist;
                    break;
                }
                auto it = lower_bound(all(row_wall[rs]), cs);
                if (it == row_wall[rs].begin()) {
                    cs = dist;
                } else {
                    it--;
                    cs = max(dist, *it + 1);
                }
                break;
            }
            case 'R': {
                ll dist = min(W - 1, cs + l);
                if (row_wall[rs].empty()) {
                    cs = dist;
                    break;
                }
                auto it = lower_bound(all(row_wall[rs]), cs);
                if (it == row_wall[rs].end()) {
                    cs = dist;
                } else {
                    cs = min(dist, *it - 1);
                }
                break;
            }
            case 'U': {
                ll dist = max(0LL, rs - l);
                if (col_wall[cs].empty()) {
                    rs = dist;
                    break;
                }
                auto it = lower_bound(all(col_wall[cs]), rs);
                if (it == col_wall[cs].begin()) {
                    rs = dist;
                } else {
                    it--;
                    rs = max(dist, *it + 1);
                }
                break;
            }
            case 'D': {
                ll dist = min(H - 1, rs + l);
                if (col_wall[cs].empty()) {
                    rs = dist;
                    break;
                }
                auto it = lower_bound(all(col_wall[cs]), rs);
                if (it == col_wall[cs].end()) {
                    rs = dist;
                } else {
                    rs = min(dist, *it - 1);
                }
                break;
            }
        }
        cout << rs + 1 << " " << cs + 1 << endl;
    }
}
