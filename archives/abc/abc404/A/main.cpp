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
    string S;
    cin >> S;
    set<char> alpha;
    for (char c = 'a'; c <= 'z'; ++c) {
        alpha.insert(c);
    }
    for (char c : S) {
        alpha.erase(c);
    }
    cout << *alpha.begin() << endl;
}
