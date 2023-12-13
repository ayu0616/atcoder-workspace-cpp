#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N, A, B, C;
    cin >> N >> A >> B >> C;
    Graph G1(N), G2(N);
    rep(i, N) rep(j, N)
    {
        ll d;
        cin >> d;
        if (i == j)
            continue;
        G1.add_edge(i, j, A * d);
        G2.add_edge(i, j, B * d + C);
    }
    auto d1 = G1.dyjkstra(0);
    auto d2 = G2.dyjkstra(N - 1);
    ll ans = LLONG_MAX;
    rep(i, N)
    {
        chmin(ans, d1[i] + d2[i]);
    }
    cout << ans << endl;
}
