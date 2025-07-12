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
    ll N;
    cin >> N;
    vs S(N);
    cin >> S;
    set<string> st;
    rep(i, N) {
        rep(j, N) {
            if (i == j) continue;
            string t = S[i] + S[j];
            st.insert(t);
        }
    }
    cout << st.size() << endl;
}
