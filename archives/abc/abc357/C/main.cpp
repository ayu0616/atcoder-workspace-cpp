#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vs carpet(int K) {
    if (K == 0) return {"#"};
    vs carpet_ = vs(pow(3, K), string(pow(3, K), '.'));
    vs low_level = carpet(K - 1);
    rep(i, 3) {
        rep(j, 3) {
            if (i == 1 && j == 1) {
                continue;
            }
            rep(k, pow(3, K - 1)) {
                rep(l, pow(3, K - 1)) { carpet_[i * pow(3, K - 1) + k][j * pow(3, K - 1) + l] = low_level[k][l]; }
            }
        }
    }
    return carpet_;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    for (auto& row : carpet(N)) {
        cout << row << endl;
    }
}
