#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    ll N, M;
    cin >> N >> M;
    vl A(N);
    cin >> A;
    rep(i, N) A[i]--;
    UnionFind<int> uf(N);
    vb visited(N, false);
    rep(i, N) {
        if (visited[i]) continue;
        visited[i] = true;
        ll j = A[i];
        while (!visited[j]) {
            visited[j] = true;
            uf.unite(i, j);
            j = A[j];
        }
    }
}
