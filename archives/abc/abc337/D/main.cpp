#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int H, W, K;
    cin >> H >> W >> K;
    vs S(H);
    cin >> S;

    int ans = 1e9;

    if (W >= K) {
        rep(h, H) {
            map<char, int> cnt;
            rep(k, K) cnt[S[h][k]]++;
            if (cnt['x'] == 0) chmin(ans, cnt['.']);
            rep(w, W - K) {
                cnt[S[h][w]]--;
                cnt[S[h][w + K]]++;
                if (cnt['x'] == 0) chmin(ans, cnt['.']);
            }
        }
    }
    if (H >= K) {
        rep(w, W) {
            map<char, int> cnt;
            rep(k, K) cnt[S[k][w]]++;
            if (cnt['x'] == 0) chmin(ans, cnt['.']);
            rep(h, H - K) {
                cnt[S[h][w]]--;
                cnt[S[h + K][w]]++;
                if (cnt['x'] == 0) chmin(ans, cnt['.']);
            }
        }
    }
    cout << ((ans == 1e9) ? -1 : ans) << endl;
}
