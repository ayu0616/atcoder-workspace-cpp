#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

struct Product {
    ll price, utility, color;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, X, K;
    cin >> N >> X >> K;
    vector<Product> P(N);
    rep(i, N) { cin >> P[i].price >> P[i].utility >> P[i].color; }

    ll dp[N + 1][X + 1];
    rep(i, N) {
        rep(j, X) {
            Product p = P[i];
            if (p.price + j > X) continue;
            chmax(dp[i + 1][j + p.price], dp[i][j] + p.utility);
        }
    }
}
