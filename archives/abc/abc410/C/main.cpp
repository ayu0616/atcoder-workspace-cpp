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
    ll N, Q;
    cin >> N >> Q;
    vl A(N);
    iota(all(A), 1);
    int head = 0;
    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            A[(head + p - 1) % N] = x;
        } else if (type == 2) {
            int p;
            cin >> p;
            cout << A[(head + p - 1) % N] << endl;
        } else {
            int k;
            cin >> k;
            head = (head + k) % N;
        }
    }
}
