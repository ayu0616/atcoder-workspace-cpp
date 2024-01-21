#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vi C(N), cnt(N);
    cin >> C;
    rep(i, N) C[i]--;
    rep(i, N) cnt[C[i]]++;
    rep(r, N) {
        vi box;
        vi col_box(N, -1);
        int ans = 0;
        rep(i, N) {
            int c = C[i];
            int box_idx = col_box[c];
            if (box_idx == -1 || box[box_idx] == K) {
                if (box.size() == M) continue;
                box_idx = box.size();
                box.push_back(0);
                col_box[c] = box_idx;
            }
            box[box_idx]++;
            ans++;
        }
        cout << ans << endl;

        int c = C[0];
        C.erase(C.begin());
        C.push_back(c);
    }
}
