#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

vl A, B;
vi v;
ll N, K;

ll f(int i = 0) {
    if (i == K - 1) {
        return A[v[i]] + B[v[i]];
    } else {
        return A[v[i]] * f(i + 1) + B[v[i]];
    }
}

int main() {
    cout << fixed << setprecision(18);
    time_t start = clock();
    cin >> N >> K;
    A.resize(N), B.resize(N);
    rep(i, N) { cin >> A[i] >> B[i]; }
    ll ans = 0;
    v.resize(N);
    iota(all(v), 0);
    while (true) {
        if (clock() - start > 1.9 * CLOCKS_PER_SEC) {
            break;
        }
        int i = random() % K;
        int j = random() % N;
        swap(v[i], v[j]);
        ll sum = f();
        if (!chmax(ans, sum)) {
            swap(v[i], v[j]);
        }
    }
    cout << ans << endl;
}
