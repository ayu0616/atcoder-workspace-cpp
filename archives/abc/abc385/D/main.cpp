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
    ll N, M, SX, SY;
    cin >> N >> M >> SX >> SY;
    SX--, SY--;
    vl X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        X[i]--, Y[i]--;
    }
    vector<char> D(M);
    vl C(M);
    rep(i, M) { cin >> D[i] >> C[i]; }
    map<ll, set<ll>> houses_by_X, houses_by_Y;
    rep(i, N) {
        houses_by_X[X[i]].insert(Y[i]);
        houses_by_Y[Y[i]].insert(X[i]);
    }
    ll ans = 0;
    ll x = SX, y = SY;
    rep(i, M) {
        char d = D[i];
        ll c = C[i];
        if (d == 'U') {
            set<ll> se = houses_by_X[x];
            ll ny = y + c;
            if (se.empty()) {
                y = ny;
                continue;
            }
            auto it = se.lower_bound(y);
            if (it == se.end()) {
                y = ny;
                continue;
            }
            while (it != se.end() && *it < ny) {
                if (y <= *it && *it <= ny) {
                    ans++;
                    se.erase(it);
                }
                it++;
            }
            y = ny;
        } else if (d == 'D') {
            set<ll> se = houses_by_X[x];
            ll ny = y - c;
            if (se.empty()) {
                y = ny;
                continue;
            }
            auto it = se.upper_bound(y);
            if (it == se.begin()) {
                if (ny <= *it && *it <= y) {
                    ans++;
                }
                y = ny;
                continue;
            }
            if(it == se.end()) {
                y = ny;
                continue;
            }
            while (it != se.begin() && *it > ny) {
                if (ny <= *it && *it <= y) {
                    ans++;
                    se.erase(it);
                }
                it--;
            }
            if (ny <= *it && *it <= y) {
                ans++;
                se.erase(it);
            }
            y = ny;
        } else if (d == 'L') {
            set<ll> se = houses_by_Y[y];
            ll nx = x - c;
            if (se.empty()) {
                x = nx;
                continue;
            }
            auto it = se.lower_bound(x);
            if (it == se.begin()) {
                if (nx <= *it && *it <= x) {
                    ans++;
                }
                x = nx;
                continue;
            }
            if(it == se.end()) {
                x = nx;
                continue;
            }
            while (it != se.begin() && *it > nx) {
                if (nx <= *it && *it <= x) {
                    ans++;
                    se.erase(it);
                }
                it--;
            }
            if (nx <= *it && *it <= x) {
                ans++;
                se.erase(it);
            }
            x = nx;
        } else if (d == 'R') {
            set<ll> se = houses_by_Y[y];
            ll nx = x + c;
            if (se.empty()) {
                x = nx;
                continue;
            }
            auto it = se.lower_bound(x);
            if (it == se.end()) {
                x = nx;
                continue;
            }
            while (it != se.end() && *it < nx) {
                if (x <= *it && *it <= nx) {
                    ans++;
                    se.erase(it);
                }
                it++;
            }
            x = nx;
        }
    }
    cout << x + 1 << " " << y + 1 << " " << ans << endl;
}
