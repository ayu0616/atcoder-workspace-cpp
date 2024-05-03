#include <algorithm>
#include <cassert>
#include <vector>

#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    vi c(9);
    cin >> c;
    vi vec = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    double ans = 0;
    double factorial_9 = 1;
    for (int i = 1; i <= 9; i++) factorial_9 *= i;

    vector<tuple<int, int, int>> cells = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6},
    };

    do {
        bool ok = true;
        for (auto [x, y, z] : cells) {
            if (c[x] == c[y] && vec[x] < vec[z] && vec[y] < vec[z]) {
                ok = false;
                break;
            } else if (c[y] == c[z] && vec[y] < vec[x] && vec[z] < vec[x]) {
                ok = false;
                break;
            } else if (c[z] == c[x] && vec[z] < vec[y] && vec[x] < vec[y]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    } while (next_permutation(all(vec)));

    cout << ans / factorial_9 << endl;
}
