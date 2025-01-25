#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll solve(vl &X, vl &Y) {
    ll N = X.size();
    ll res = 0;
    sort(all(X));
    sort(all(Y));
    rep(i, N) { res += (2 * i - N + 1) * X[i]; }
    rep(i, N) { res += (2 * i - N + 1) * Y[i]; }
    return res / 2;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N;
    vl X(N), Y(N);
    rep(i, N) {
        ll x, y;
        cin >> x >> y;
        X[i] = x - y;
        Y[i] = x + y;
    }
    vl X1, Y1, X2, Y2;
    rep(i, N) {
        if (X[i] %2==0&& Y[i] % 2 == 0) {
            X1.push_back(X[i]);
            Y1.push_back(Y[i]);
        } else {
            X2.push_back(X[i]);
            Y2.push_back(Y[i]);
        }
    }
    cout << solve(X1, Y1) + solve(X2, Y2) << endl;
}
