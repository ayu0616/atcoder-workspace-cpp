#include <numeric>
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
    ll N;
    cin >> N;
    vl T(N), V(N);
    rep(i, N) cin >> T[i] >> V[i];
    vl water(T.back() + 1, 0);
    rep(i, 1, T.back() + 1) {
        water[i] = water[i - 1];
        if (find(all(T), i) != T.end()) {
            water[i] += V[distance(T.begin(), find(all(T), i))];
        }
        water[i] = max(water[i] - 1, 0);
    }
    cout << water.back() + 1 << endl;
}
