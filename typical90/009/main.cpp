#include <cassert>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

double getangle(Point<double> pt) {
    auto [x, y] = pt;
    double I = x / pt.abs();
    if (y >= 0) {
        return acos(I) * 180.0 / M_PI;
    } else {
        return 360.0 - acos(I) * 180.0 / M_PI;
    }
}

double getangle_2(double ang_1, double ang_2) {
    double angle = abs(ang_1 - ang_2);
    if (angle >= 180.0) angle = 360.0 - angle;
    return angle;
}

int main() {
    double N;
    cin >> N;
    vector<Point<double>> pt(N);
    rep(i, N) { cin >> pt[i].x >> pt[i].y; }
    double ans = 0;
    rep(j, N) {
        vector<double> v;
        rep(i, N) {
            if (i == j) continue;
            double angle = getangle(pt[i] - pt[j]);
            v.push_back(angle);
        }
        sort(all(v));
        assert(*v.begin() >= 0);
        assert(*v.rbegin() <= 360.0);
        rep(i, v.size()) {
            double angle_ab = v[i];
            double angle_bc_tmp = angle_ab + 180.0;
            while (angle_bc_tmp >= 360.0) angle_bc_tmp -= 360.0;
            int idx1 = lower_bound(all(v), angle_bc_tmp) - v.begin();
            int idx2 = (idx1 + v.size() - 1) % (v.size());
            int idx3 = (idx1 + 1) % (v.size());
            double angle1 = getangle_2(angle_ab, v[idx1]);
            double angle2 = getangle_2(angle_ab, v[idx2]);
            double angle3 = getangle_2(angle_ab, v[idx3]);
            ans = max({ans, angle1, angle2, angle3});
        }
    }
    printf("%.100f\n", ans);
}
