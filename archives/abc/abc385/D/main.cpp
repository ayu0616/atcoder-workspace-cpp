#include <vector>
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
    ll N, M, Sx, Sy;
    cin >> N >> M >> Sx >> Sy;
    vl X(N), Y(N), C(M);
    vector<char> D(M);
    rep(i, N) cin >> X[i] >> Y[i];
    rep(i, M) cin >> D[i] >> C[i];
    map<ll, set<ll>> xy, yx;
    rep(i, N) {
        xy[X[i]].insert(Y[i]);
        yx[Y[i]].insert(X[i]);
    }
    ll ans = 0;
    ll x = Sx, y = Sy;
    rep(i, M) {
        char d = D[i];
        ll c = C[i];
        if (d == 'U') {
            auto lit = xy[x].lower_bound(y);
            if (lit == xy[x].end()) {
                y += c;
                continue;
            }
            auto rit = xy[x].upper_bound(y + c);
            vector<ll> yv;
            for (auto it = lit; it != rit; it++) {
                yv.push_back(*it);
            }
            for (auto y : yv) {
                ans++;
                xy[x].erase(y);
                yx[y].erase(x);
            }
            y += c;
        } else if (d == 'D') {
            auto lit = xy[x].lower_bound(y - c);
            if (lit == xy[x].end()) {
                y -= c;
                continue;
            }
            auto rit = xy[x].upper_bound(y);
            vector<ll> yv;
            for (auto it = lit; it != rit; it++) {
                yv.push_back(*it);
            }
            for (auto y : yv) {
                ans++;
                xy[x].erase(y);
                yx[y].erase(x);
            }
            y -= c;
        } else if (d == 'R') {
            auto lit = yx[y].lower_bound(x);
            if (lit == yx[y].end()) {
                x += c;
                continue;
            }
            auto rit = yx[y].upper_bound(x + c);
            vector<ll> xv;
            for (auto it = lit; it != rit; it++) {
                xv.push_back(*it);
            }
            for (auto x : xv) {
                ans++;
                xy[x].erase(y);
                yx[y].erase(x);
            }
            x += c;
        } else if (d == 'L') {
            auto lit = yx[y].lower_bound(x - c);
            if (lit == yx[y].end()) {
                x -= c;
                continue;
            }
            auto rit = yx[y].upper_bound(x);
            vector<ll> xv;
            for (auto it = lit; it != rit; it++) {
                xv.push_back(*it);
            }
            for (auto x : xv) {
                ans++;
                xy[x].erase(y);
                yx[y].erase(x);
            }
            x -= c;
        }
    }
    cout << vector({x, y, ans}) << endl;
}
