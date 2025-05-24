#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/all.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;
    vl cnt(M + 1);
    rep(i, N) { cnt[A[i]]++; }
    rep(i, 1, M + 1) {
        if (cnt[i] == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i, N) {
        cnt[A[N - i - 1]]--;
        if (cnt[A[N - i - 1]] == 0) {
            cout << i + 1 << endl;
            return 0;
        }
    }
}
