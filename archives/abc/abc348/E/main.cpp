#include <numeric>
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
    ll N;
    cin >> N;
    vl A(N - 1), B(N - 1), C(N);
    rep(i, N - 1) cin >> A[i] >> B[i];
    cin >> C;
    Graph g(N);
    rep(i, N - 1) {
        A[i]--;
        B[i]--;
        g.add_edge(A[i], B[i]);
        g.add_edge(B[i], A[i]);
    }

    ll csum = accumulate(all(C), 0LL);

    // 0を根とする根付き木として考える
    int root = 0;

    vl st_sum(N);
    auto calc_st_sum = [&](auto &&self, int v, int p) -> void {
        st_sum[v] = C[v];
        for (auto e : g[v]) {
            if (e.to->id == p) continue;
            self(self, e.to->id, v);
            st_sum[v] += st_sum[e.to->id];
        }
    };
    calc_st_sum(calc_st_sum, root, -1);

    auto get_center = [&](auto &&self, int v, int p) -> int {
        bool is_center = true;
        for (auto e : g[v]) {
            if (e.to->id == p) continue;
            int res = self(self, e.to->id, v);
            if (res != -1) return res;
            if (st_sum[e.to->id] * 2 > csum) is_center = false;
        }
        if (csum - st_sum[v] > csum / 2) is_center = false;
        if (is_center) return v;
        return -1;
    };
    const int center = get_center(get_center, root, -1);

    vl d(N, -1);
    queue<int> q;
    q.push(center);
    d[center] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto e : g[v]) {
            if (d[e.to->id] != -1) continue;
            d[e.to->id] = d[v] + 1;
            q.push(e.to->id);
        }
    }
    ll ans = 0;
    rep(i, N) { ans += C[i] * d[i]; }
    cout << ans << endl;
}
