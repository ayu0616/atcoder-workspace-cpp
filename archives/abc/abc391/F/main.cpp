#include <functional>
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
    ll N, K;
    cin >> N >> K;
    vl A(N), B(N), C(N);
    cin >> A >> B >> C;
    sort(all(A));
    sort(all(B));
    sort(all(C));
    reverse(all(A));
    reverse(all(B));
    reverse(all(C));
    map<tuple<int, int, int>, bool> mp;
    vl ans;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    int depth = 0;
    while (!q.empty()) {
        auto [a, b, c] = q.front();
        q.pop();
        if (depth < a + b + c && ans.size() >= K) {
            break;
        }
        depth = a + b + c;
        if (mp[{a, b, c}]) continue;
        mp[{a, b, c}] = true;
        ans.push_back(A[a] * B[b] + B[b] * C[c] + C[c] * A[a]);
        if (a + 1 < N) q.push({a + 1, b, c});
        if (b + 1 < N) q.push({a, b + 1, c});
        if (c + 1 < N) q.push({a, b, c + 1});
    }
    sort(all(ans));
    reverse(all(ans));
    cout << ans[K - 1] << endl;
}
