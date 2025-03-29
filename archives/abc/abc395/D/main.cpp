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

struct House {
    int num;
};

int main() {
    cout << fixed << setprecision(18);
    ll N, Q;
    cin >> N >> Q;
    vector<House*> pegions(N);
    vector<House*> houses(N);
    vector<House*> house_archives(N);
    rep(i, N) {
        houses[i] = new House{(int)i};
        pegions[i] = houses[i];
        house_archives[i] = houses[i];
    }
    rep(Q) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            pegions[a] = houses[b];
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            swap(houses[a], houses[b]);
            houses[a]->num = a;
            houses[b]->num = b;
        } else {
            int a;
            cin >> a;
            a--;
            cout << pegions[a]->num + 1 << endl;
        }
    }
}
