#include <ctime>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    time_t start = clock();
    ll N;
    cin >> N;
    vi K(N);
    vector<set<int>> A(N);
    vector<map<int, ll>> B(N);
    rep(i, N) {
        cin >> K[i];
        rep(j, K[i]) {
            int a;
            cin >> a;
            A[i].insert(a);
            B[i][a]++;
        }
    }
    double ans = 0;
    rep(i, N) rep(j, i + 1, N) {
        ll cnt = 0;
        if (A[i].size() > A[j].size()) {
            for (auto a : A[j]) {
                cnt += B[i][a] * B[j][a];
            }
        } else {
            for (auto a : A[i]) {
                cnt += B[i][a] * B[j][a];
            }
        }
        chmax(ans, (double)cnt / K[i] / K[j]);
        if (clock() - start > 1.9 * CLOCKS_PER_SEC) {
            cout << ans << endl;
            return 0;
        }
    }
    cout << ans << endl;
}
