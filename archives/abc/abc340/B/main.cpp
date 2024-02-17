#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int Q;
    cin >> Q;
    vi arr;
    rep(i, Q) {
        int typ, x;
        cin >> typ >> x;
        if (typ == 1) {
            arr.push_back(x);
        } else {
            cout << arr[arr.size() - x] << endl;
        }
    }
}
