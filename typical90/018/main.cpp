#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(10);

    double T, L, X, Y, Q;
    cin >> T >> L >> X >> Y >> Q;

    auto current_pos = [&](double t) {
        double x, y, z;
        double theta = t / T * 2 * M_PI - (M_PI / 2);
        x = 0;
        y = -cos(theta) * L / 2;
        z = sin(theta) * L / 2 + L / 2;
        return tuple{x, y, z};
    };

    while (Q--) {
        double E;
        cin >> E;
        auto [x, y, z] = current_pos(E);
        double AB = sqrt(X * X + (Y - y) * (Y - y));
        double BC = z;
        double ans = atan(BC / AB) / M_PI * 180;
        if (ans < 0) ans += 180;
        cout << ans << endl;
    }
}
