#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <atcoder/string.hpp>

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int binary_search(const vi& sa, const string& S, const string& T) {
    int ng = -1, ok = sa.size();
    while (ok - ng > 1) {
        int mid = (ok + ng) / 2;
        if (S.compare(sa[mid], T.size(), T) >= 0) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cout << fixed << setprecision(18);
    string S;
    ll Q;
    cin >> S >> Q;
    auto sa = atcoder::suffix_array(S);
    while (Q--) {
        string T;
        cin >> T;
        int l = binary_search(sa, S, T);
        int r = binary_search(sa, S, T + char(127));
        // debug(l);
        // debug(r);
        cout << r - l << endl;
    }
}
