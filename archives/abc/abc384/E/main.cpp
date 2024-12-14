#include <functional>
#include <queue>
#include <vector>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Slime {
    ll s, h, w;
};

bool operator<(const Slime &lhs, const Slime &rhs) { return lhs.s < rhs.s; }
bool operator>(const Slime &lhs, const Slime &rhs) { return lhs.s > rhs.s; }

int main() {
    cout << fixed << setprecision(18);
    ll H, W, X, P, Q;
    cin >> H >> W >> X >> P >> Q;
    P--, Q--;
    vvl S(H, vl(W));
    cin >> S;
    priority_queue<Slime, vector<Slime>, greater<Slime>> slimes;
    vvb merged(H, vb(W));
    merged[P][Q] = true;
    ll ans = S[P][Q];
    rep(i, 4) {
        ll nh = P + dy4[i];
        ll nw = Q + dx4[i];
        if (0 <= nh && nh < H && 0 <= nw && nw < W) {
            slimes.push({S[nh][nw], nh, nw});
        }
    }
    while (true) {
        if (slimes.empty()) {
            break;
        }
        auto [s, h, w] = slimes.top();
        slimes.pop();
        if (merged[h][w]) {
            continue;
        }
        if(LL_INF / s < X) {
            break;
        }
        if (s * X >= ans) {
            break;
        }
        merged[h][w] = true;
        ans += s;
        rep(i, 4) {
            ll nh = h + dy4[i];
            ll nw = w + dx4[i];
            if (0 <= nh && nh < H && 0 <= nw && nw < W) {
                slimes.push({S[nh][nw], nh, nw});
            }
        }
    }
    cout << ans << endl;
}
