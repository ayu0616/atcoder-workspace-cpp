#include <functional>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N;
vl A, B;

map<tuple<ll, vl, int>, int> memo;
int f(ll i, vector<ll> pow, int n) {
    if (memo.count({i, pow, n})) {
        return memo[{i, pow, n}];
    }
    if (i == N) {
        if (pow[0] == pow[1] && pow[1] == pow[2]) {
            return memo[{i, pow, n}] = n;
        } else {
            return memo[{i, pow, n}] = INT_INF;
        }
    }
    ll a = A[i], b = B[i];
    a--;
    int res = INT_INF;
    rep(t, 3) {
        if (t == a) {
            chmin(res, f(i + 1, pow, n));
            continue;
        }
        auto pow2 = pow;
        pow2[t] += b;
        pow2[a] -= b;
        chmin(res, f(i + 1, pow2, n + 1));
    }
    return memo[{i, pow, n}] = res;
};

int main() {
    cout << fixed << setprecision(18);
    cin >> N;
    A.resize(N), B.resize(N);
    rep(i, N) { cin >> A[i] >> B[i]; }

    vl pow(3, 0);
    rep(i, N) { pow[A[i] - 1] += B[i]; }

    int ans = f(0, pow, 0);
    if (ans == INT_INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
