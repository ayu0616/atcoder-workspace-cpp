#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int query(int a, int b, int c, int d) {
    cout << "? " << a + 1 << " " << b << " " << c + 1 << " " << d << endl;
    int res;
    cin >> res;
    return res;
}

void answer(int x, int y) { cout << "! " << x + 1 << " " << y + 1 << endl; }

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    int lx = 0, rx = N;
    while (rx - lx > 1) {
        int mx = (lx + rx) / 2;
        int resx = query(lx, mx, 0, N);
        if (resx < mx - lx) {
            rx = mx;
        } else {
            lx = mx;
        }
    }
    int ly = 0, ry = N;
    while ( ry - ly > 1) {
            int my = (ly + ry) / 2;
            int resy = query(0, N, ly, my);
            if (resy < my - ly) {
                ry = my;
            } else {
                ly = my;
            }
    }
    answer(lx, ly);
}
