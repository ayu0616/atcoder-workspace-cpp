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
    ll N = S.size();
    string suf = "";
    string suf_rev = "";
    rep(i, N){
        suf += S[N - i - 1];
        suf_rev = S[N - i - 1] + suf_rev;
    }
}
