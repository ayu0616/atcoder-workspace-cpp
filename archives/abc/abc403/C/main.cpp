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
    ll N, M, Q;
    cin >> N >> M >> Q;
    vb all_ok(N, false);
    vector<set<int>> S(N);
    rep(i, Q) {
        int type;
        cin >> type;
        switch (type) {
            case 1: {
                int X, Y;
                cin >> X >> Y;
                X--;
                Y--;
                S[X].insert(Y);
                break;
            }
            case 2: {
                int X;
                cin >> X;
                X--;
                all_ok[X] = true;
                break;
            }
            case 3: {
                int X, Y;
                cin >> X >> Y;
                X--;
                Y--;
                bool ok = all_ok[X] || S[X].count(Y);
                cout << (ok ? "Yes" : "No") << endl;
            }
        }
    }
}
