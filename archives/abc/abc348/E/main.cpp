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
    cin >> N;
    vvi edges(N);
    rep(i, N - 1) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        edges[A].push_back(B);
        edges[B].push_back(A);
    }
    vl C(N);
    cin >> C;

    auto d = [&](int x, int y) { return abs(x - y); };

    auto f = [&](int x) {
        ll res = 0;
        rep(i, N) { res += C[i] * d(i, x); }
        return res;
    }
}
