#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    ll N, M;
    cin >> N >> M;
    vi X(M);
    cin >> X;
    rep(i, M) { X[i]--; }
    Graph g(N);
    rep(i, N) {
        g.add_edge(i, (i + 1) % N);
        g.add_edge((i + 1) % N, i);
    }
    SegTree seg(N);
    seg.update(0, N, 0);
    ll before = 0;
    rep(i, M - 1) {
        ll a = X[i], b = X[i + 1];
        if (a > b) swap(a, b);
        ll dl = N - b + a;
        ll dr = b - a;
        before += min(dl, dr);
        if (dl < dr) {
            ll diff = dr - dl;
            ll cur = min(seg.query(0, a), seg.query(b, N));
            seg.update(0, a, cur + diff);
            seg.update(b, N, cur + diff);
        } else if (dl > dr) {
            ll diff = dl - dr;
            ll cur = seg.query(a, b);
            seg.update(a, b, cur + diff);
        }
    }
    ll ans = before + seg.query(0, N);
    cout << ans << endl;
    // rep(i, N) { cout<<seg.query(i, i+1)<<endl;}
}
