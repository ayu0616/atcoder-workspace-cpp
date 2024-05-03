#include <cstdlib>
#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

string T_dash;

bool judge(const string &S) {
    if (S == T_dash) return true;
    if (abs((int)S.size() - (int)T_dash.size()) > 1) return false;
    int min_size = min(S.size(), T_dash.size());
    int idx = -1;
    rep(i, min_size) {
        if (S[i] != T_dash[i]) {
            idx = i;
            break;
        }
    }
    if (idx == -1 && S.substr(0, min_size) == T_dash.substr(0, min_size)) return true;
    if (S.size() == T_dash.size() && S.substr(idx + 1) == T_dash.substr(idx + 1)) return true;
    if (S.size() == T_dash.size() + 1 && S.substr(idx + 1) == T_dash.substr(idx)) return true;
    if (S.size() == T_dash.size() - 1 && S.substr(idx) == T_dash.substr(idx + 1)) return true;
    return false;
}

int main() {
    cout << fixed << setprecision(18);
    ll N;
    cin >> N >> T_dash;
    vs S(N);
    cin >> S;
    vi ans;
    rep(i, N) {
        if (judge(S[i])) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    if (ans.size()) cout << ans << endl;
}
