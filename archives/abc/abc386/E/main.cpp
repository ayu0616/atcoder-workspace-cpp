#include <ctime>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

ll N, K;
ll sum = 0;
ll ans = 0;
vl A;
stack<int> combi;
int max_log = 0;

inline void solve() {
    if (combi.size() == K) {
        chmax(ans, sum);
    } else {
        for (int i = combi.top() + 1; i < N; ++i) {
            int siz = combi.size();
            if (N - i + siz < K) {
                break;
            }
            if (A[i] >> (max_log - 1)&1) {
                break;
            }
            combi.push(i);
            sum ^= A[i];
            solve();
            combi.pop();
            sum ^= A[i];
        }
    }
}

int main() {
    cout << fixed << setprecision(18);
    cin >> N >> K;
    A.resize(N);
    cin >> A;
    sort(all(A));
    reverse(all(A));
    while ((1LL << max_log) <= A[0]) {
        ++max_log;
    }
    rep(i, N) {
        combi.push(i);
        sum = A[i];
        solve();
        combi.pop();
        if(A[i] < (1LL << (max_log-1))) {
            break;
        }
    }
    cout << ans << endl;
}
