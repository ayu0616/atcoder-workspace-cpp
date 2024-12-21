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
    ll H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X--, Y--;
    vs S(H);
    string T;
    cin >> S >> T;
    set<pll> houses;
    for (auto t : T) {
        ll nx = X, ny = Y;
        if (t == 'U') {
            nx--;
        } else if (t == 'D') {
            nx++;
        } else if (t == 'L') {
            ny--;
        } else if (t == 'R') {
            ny++;
        }
        if (nx < 0 || nx >= H || ny < 0 || ny >= W) {
            continue;
        }
        if (S[nx][ny] == '#') {
            continue;
        }
        if (S[nx][ny] == '@') {
            houses.insert({nx, ny});
        }
        X = nx;
        Y = ny;
    }
    cout << X + 1 << " " << Y + 1 << " " << houses.size() << endl;
}
