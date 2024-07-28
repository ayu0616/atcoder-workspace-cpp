#include <iostream>
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
    ll H, W;
    cin >> H >> W;
    ll si, sj;
    cin >> si >> sj;
    vs C(H);
    cin >> C;
    string X;
    cin >> X;
    ll i = si - 1, j = sj - 1;
    for (auto x : X) {
        if (x == 'U') {
            if (i == 0) continue;
            if (C[i - 1][j] == '#') continue;
            i--;
        } else if (x == 'D') {
            if (i == H - 1) continue;
            if (C[i + 1][j] == '#') continue;
            i++;
        } else if (x == 'L') {
            if (j == 0) continue;
            if (C[i][j - 1] == '#') continue;
            j--;
        } else if (x == 'R') {
            if (j == W - 1) continue;
            if (C[i][j + 1] == '#') continue;
            j++;
        }
    }
    cout << i + 1 << " " << j + 1 << endl;
}
