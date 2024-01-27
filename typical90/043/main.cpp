#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int H, W;
    cin >> H >> W;
    int rs, cs, rt, ct;
    cin >> rs >> cs >> rt >> ct;
    rs--, cs--, rt--, ct--;
    vs S(H);
    cin >> S;
    vvi dp(H * W, vi(4, INT_INF));

    auto pos = [&](int h, int w) { return h * W + w; };
    auto invalid = [&](int h, int w) { return h < 0 || H <= h || w < 0 || W <= w || S[h][w] == '#'; };
    rep(i, 4) dp[pos(rs, cs)][i] = 0;

    queue<tuple<int, int, int>> q;
    rep(i, 4) q.emplace(rs, cs, i);
    while (q.size()) {
        auto [h, w, way] = q.front();
        q.pop();
        int p = pos(h, w);
        rep(i, 4) {
            int nh = h + dy4[i], nw = w + dx4[i];
            int np = pos(nh, nw);
            if (invalid(nh, nw)) continue;
            if (dp[np][i] != INT_INF) continue;
            bool chose = chmin(dp[np][i], dp[p][way] + (way != i));
            if (chose) q.emplace(nh, nw, i);
        }
    }

    cerr << dp << endl;
    cout << min(dp[pos(rt, ct)]) << endl;
}
