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
    ll N, M;
    cin >> N >> M;
    vl A(M);
    cin >> A;
    vl cur(M, 0);
    rep(i, N) {
        vl X(M, 0);
        cin >> X;
        rep(j, M) {
            cur[j] += X[j];
        }
    }
    rep(i, M) {
        if (A[i] > cur[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}
