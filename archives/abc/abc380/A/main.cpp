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
    string N;
    cin >> N;
    sort(all(N));
    if (N == "122333") {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
