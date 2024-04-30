#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int M, D, y, m, d;
    cin >> M >> D >> y >> m >> d;
    d++;
    if (d == D + 1) {
        d = 1;
        m++;
    }
    if (m == M + 1) {
        m = 1;
        y++;
    }
    cout << y << " " << m << " " << d << endl;
}
