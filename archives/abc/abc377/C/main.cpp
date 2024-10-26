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
    ll N, M;
    cin >> N >> M;
    vl a(M), b(M);
    rep(i, M) cin >> a[i] >> b[i];
    set<pll> rev;
    rep(i, M) {
        rev.insert({a[i], b[i]});
        int na = a[i] + 2, nb = b[i] + 1;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] + 1, nb = b[i] + 2;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] - 1, nb = b[i] + 2;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] - 2, nb = b[i] + 1;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] - 2, nb = b[i] - 1;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] - 1, nb = b[i] - 2;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] + 1, nb = b[i] - 2;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
        na = a[i] + 2, nb = b[i] - 1;
        if (1 <= na && na <= N && 1 <= nb && nb <= N) {
            rev.insert({na, nb});
        }
    }
    cout << N * N - rev.size() << endl;
}
