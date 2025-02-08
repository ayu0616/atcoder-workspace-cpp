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
    int H, W;
    cin >> H >> W;
    int h = H, w = W;
    vs c(H);
    cin >> c;
    vvi rowc(H, vi(26)), colc(W, vi(26));
    rep(i, H) {
        rep(j, W) {
            rowc[i][c[i][j] - 'a']++;
            colc[j][c[i][j] - 'a']++;
        }
    }
    vb row_deleted(H), col_deleted(W);
    while (true) {
        set<int> rows, cols;
        if (w >= 2) {
            rep(i, H) {
                if (row_deleted[i]) continue;
                rep(cl, 26) {
                    if (rowc[i][cl] == w) {
                        rows.insert(i);
                    }
                }
            }
        }
        if (h >= 2) {
            rep(j, W) {
                if (col_deleted[j]) continue;
                rep(cl, 26) {
                    if (colc[j][cl] == h) {
                        cols.insert(j);
                    }
                }
            }
        }
        if (rows.empty() && cols.empty()) {
            break;
        }
        for (int i : rows) {
            row_deleted[i] = true;
            rep(j, W) {
                if (c[i][j] == '.') continue;
                rowc[i][c[i][j] - 'a']--;
                colc[j][c[i][j] - 'a']--;
                c[i][j] = '.';
            }
        }
        for (int j : cols) {
            col_deleted[j] = true;
            rep(i, H) {
                if (c[i][j] == '.') continue;
                colc[j][c[i][j] - 'a']--;
                rowc[i][c[i][j] - 'a']--;
                c[i][j] = '.';
            }
        }
        h -= rows.size();
        w -= cols.size();
    }
    cout << h * w << endl;
}
