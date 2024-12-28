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
    vi card(4);
    cin >> card;
    sort(all(card));
    bool ok = false;
    if(card[0] == card[1] && card[2] == card[3]) {
        if(card[0] != card[2]) {
            ok = true;
        }
    }
    if(card[0] == card[1] && card[1] == card[2]) {
        if(card[0] != card[3]) {
            ok = true;
        }
    }
    if(card[1] == card[2] && card[2] == card[3]) {
        if(card[0] != card[1]) {
            ok = true;
        }
    }
    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
