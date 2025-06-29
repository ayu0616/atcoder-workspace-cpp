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
    vvi G(N, vi(N));
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u > v) {
            swap(u, v);
        }
        G[u][v] = 1;
    }
    vi nodes(N);
    iota(all(nodes), 0);
    ll ans = LL_INF;
    do {
        vvi G2(N, vi(N));
        rep(i, N) {
            int u = nodes[i], v = nodes[(i + 1) % N];
            if (u > v) {
                swap(u, v);
            }
            G2[u][v] = 1;
        }
        ll cnt = 0;
        rep(u, N) {
            rep(v, u + 1, N) { cnt += abs(G[u][v] - G2[u][v]); }
        }
        chmin(ans, cnt);
        if (N == 6) {
            vvi G3(N, vi(N));
            rep(i, 3) {
                int u = nodes[i], v = nodes[(i + 1) % 3];
                if (u > v) {
                    swap(u, v);
                }
                G3[u][v] = 1;
            }
            rep(i, 3) {
                int u = nodes[i + 3], v = nodes[(i + 1) % 3 + 3];
                if (u > v) {
                    swap(u, v);
                }
                G3[u][v] = 1;
            }
            ll cnt2 = 0;
            rep(u, N) {
                rep(v, u + 1, N) { cnt2 += abs(G[u][v] - G3[u][v]); }
            }
            chmin(ans, cnt2);
        } else if (N == 7) {
            vvi G3(N, vi(N));
            rep(i, 3) {
                int u = nodes[i], v = nodes[(i + 1) % 3];
                if (u > v) {
                    swap(u, v);
                }
                G3[u][v] = 1;
            }
            rep(i, 4) {
                int u = nodes[i + 3], v = nodes[(i + 1) % 4 + 3];
                if (u > v) {
                    swap(u, v);
                }
                G3[u][v] = 1;
            }
            ll cnt2 = 0;
            rep(u, N) {
                rep(v, u + 1, N) { cnt2 += abs(G[u][v] - G3[u][v]); }
            }
            chmin(ans, cnt2);
        } else if (N == 8) {
            vvi G3(N, vi(N));
            rep(i, 3) {
                int u = nodes[i], v = nodes[(i + 1) % 3];
                if (u > v) {
                    swap(u, v);
                }
                G3[u][v] = 1;
            }
            rep(i, 5) {
                int u = nodes[i + 3], v = nodes[(i + 1) % 5 + 3];
                if (u > v) {
                    swap(u, v);
                }
                G3[u][v] = 1;
            }
            ll cnt2 = 0;
            rep(u, N) {
                rep(v, u + 1, N) { cnt2 += abs(G[u][v] - G3[u][v]); }
            }
            chmin(ans, cnt2);

            vvi G4(N, vi(N));
            rep(i, 4) {
                int u = nodes[i], v = nodes[(i + 1) % 4];
                if (u > v) {
                    swap(u, v);
                }
                G4[u][v] = 1;
            }
            rep(i, 4) {
                int u = nodes[i + 4], v = nodes[(i + 1) % 4 + 4];
                if (u > v) {
                    swap(u, v);
                }
                G4[u][v] = 1;
            }
            ll cnt3 = 0;
            rep(u, N) {
                rep(v, u + 1, N) { cnt3 += abs(G[u][v] - G4[u][v]); }
            }
            chmin(ans, cnt3);
        }
    } while (next_permutation(all(nodes)));
    cout << ans << endl;
}
