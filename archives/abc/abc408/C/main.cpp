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
    cin >> N>>M;
    vl L(M), R(M);
    rep(i, M) cin >> L[i] >> R[i];
    vl A(N+1);
    rep(i, M) L[i]--;
    rep(i,M){
        A[L[i]]++;
        A[R[i]]--;
    }
    int cur=0;
    int min = INT_INF;
    rep(i, N){
        cur+=A[i];
        if(cur<min){
            min=cur;
        }
    }
    cout << min << endl;
    return 0;
}
