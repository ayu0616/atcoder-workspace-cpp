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
    ll N, M;
    cin >> N >> M;
    vl X(M), Y(M);
    vector<char> C(M);
    rep(i, M) { cin >> X[i] >> Y[i] >> C[i]; }
    set<ll> sx, sy;
    rep(i, M) {
        sx.insert(X[i]);
        sy.insert(Y[i]);
    }
    vl vx, vy;
    for (auto x : sx) {
        vx.push_back(x);
    }
    for (auto y : sy) {
        vy.push_back(y);
    }
    sort(all(vx));
    sort(all(vy));
    map<ll, ll> mx, my;
    rep(i, vx.size()) { mx[vx[i]] = i; }
    rep(i, vy.size()) { my[vy[i]] = i; }

    int xsize = vx.size();
    int ysize = vy.size();

    vl ymin(xsize, LL_INF);
    rep(i, M) {
        if (C[i] == 'W') {
            int xi = mx[X[i]];
            int yi = my[Y[i]];
            ymin[xi] = min(ymin[xi], yi);
        }
    }
    rep(i, xsize - 1) { chmin(ymin[i + 1], ymin[i]); }
    rep(i, M) {
        if (C[i] == 'B') {
            int xi = mx[X[i]];
            int yi = my[Y[i]];
            if (ymin[xi] <= yi) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
