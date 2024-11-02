#include <algorithm>
#include <numeric>
#include <queue>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

void solve() {
    ll N, K;
    cin >> N >> K;
    vl A(N), B(N);
    cin >> A >> B;
    vpll AB(N);
    rep(i, N) { AB[i] = {A[i], B[i]}; }
    sort(all(AB));
    ll ans = LL_INF;

    priority_queue<ll> pq;
    rep(i, K) { pq.push(AB[i].second); }
    ll sumB = accumulate(AB.begin(), AB.begin() + K, 0LL, [](ll acc, pll ab) { return acc + ab.second; });
    chmin(ans, AB[K - 1].first * sumB);

    rep(i, K, N) {
        auto [a, b] = AB[i];
        pq.push(b);
        int maxB = pq.top();
        pq.pop();
        sumB += b;
        sumB -= maxB;
        chmin(ans, a * sumB);
    }

    cout << ans << endl;
}

int main() {
    cout << fixed << setprecision(18);
    int T;
    cin >> T;
    rep(T) { solve(); }
}
