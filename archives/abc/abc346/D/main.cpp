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
    int N;
    string S;
    cin >> N >> S;
    vl C(N);
    cin >> C;
    vl front_01(N + 1, 0);
    vl front_10(N + 1, 0);
    rep(i, N) {
        front_01[i + 1] = front_01[i];
        front_10[i + 1] = front_10[i];
        if (i % 2 == 0) {
            if (S[i] == '0') {
                front_10[i + 1] += C[i];
            } else {
                front_01[i + 1] += C[i];
            }
        } else {
            if (S[i] == '0') {
                front_01[i + 1] += C[i];
            } else {
                front_10[i + 1] += C[i];
            }
        }
    }

    ll min_cost = 1LL << 62;

    rep(i, N - 1) {
        ll c = min(front_01[i + 1] + (front_10[N] - front_10[i + 1]), front_10[i + 1] + (front_01[N] - front_01[i + 1]));
        min_cost = min(min_cost, c);
    }

    cout << min_cost << endl;
}
