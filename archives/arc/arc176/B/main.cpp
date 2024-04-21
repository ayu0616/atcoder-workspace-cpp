#include <climits>
#include <iostream>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<10>;
constexpr int num[] = {2, 4, 8, 6};

int main() {
    cout << fixed << setprecision(18);
    int T;
    cin >> T;
    while (T--) {
        ll N, M, K;
        cin >> N >> M >> K;
        // ll k = K % 10;
        // if (N < M) {
        //     continue;
        // }
        // ll q = 0;
        // ll mk = (M - K) % 4;
        // rep(i, mk) { q += num[(N - M + (4 - mk) * i) % 4]; }
        // q %= 10;
        // if (mk == 0) {
        //     ll cnt = (N / (M - K)) % 10;
        //     q = (num[(N - M) % 4] * cnt) % 10;
        // } else if (mk == 1) {
        //     ll cnt = (N / (M - K)) % 10;
        //     q = (2 + 4 + 8 + 6) * (cnt / 4);
        //     rep(i, cnt % 4) {
        //         int idx = (N - M + i) % 4;
        //         q += num[idx];
        //     }
        //     q %= 10;
        // } else if (mk == 2) {
        //     ll cnt = (N / (M - K)) % 10;
        //     q = (num[(N - M) % 4] + num[(N - M + 2) % 4]) * (cnt / 2);
        //     rep(i, cnt % 2) {
        //         int idx = (N - M + 2 * i) % 4;
        //         q += num[idx];
        //     }
        //     q %= 10;
        // } else if (mk == 3) {
        //     ll cnt = (N / (M - K)) % 10;
        //     q = (2 + 4 + 8 + 6) * (cnt / 4);
        //     rep(i, cnt % 4) {
        //         int idx = (N - M + 3 * i) % 4;
        //         q += num[idx];
        //     }
        //     q %= 10;
        // }
        // for (ll i = N - M; i >= 0; i -= (M - K)) {
        //     q += mint(2LL).pow(i);
        // }
        // ll n = num[(N - 1) % 4];
        // ll m = num[(M - 1) % 4];
        // ll k = num[(K - 1) % 4];
        // ll r = n - q * (m - k + 10);
        // while (r < 0) {
        //     r += INT_INF * 10LL;
        //     r %= 10;
        // }
        if (M - K == 1) {
            if (N >= K - 1)
                cout << 0 << endl;
            else
                cout << mint(2).pow(N) << endl;
            continue;
        }
        ll v = N % (M - K);
        v += ((M - 1) - v) / (M - K) * (M - K) + 4;
        if (N < M) v = N;
        mint r = mint(2).pow(v);
        cout << r << endl;
    }
}
