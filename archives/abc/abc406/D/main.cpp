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
    ll H, W, N;
    cin >> H >> W >> N;
    vl X(N), Y(N);
    rep(i, N) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
    }

    vector<set<ll>> S(H), T(W);
    rep(i, N) {
        S[X[i]].insert(Y[i]);
        T[Y[i]].insert(X[i]);
    }

    ll Q;
    cin >> Q;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            x--;
            cout<< S[x].size() << endl;
            for (auto it = S[x].begin(); it != S[x].end(); it++) {
                T[*it].erase(x);
            }
            S[x].clear();
        } else {
            ll y;
            cin >> y;
            y--;
            cout<< T[y].size() << endl;
            for (auto it = T[y].begin(); it != T[y].end(); it++) {
                S[*it].erase(y);
            }
            T[y].clear();
        }
    }
}
