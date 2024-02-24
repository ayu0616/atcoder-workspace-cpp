#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    set<int> st;
    rep(i, N - 1) {
        if (S[i] == S[i + 1]) st.insert(i + 1);
    }
    while (Q--) {
        int typ, L, R;
        cin >> typ >> L >> R;
        L--, R--;
        if (typ == 1) {
            if (L > 0) {
                if (st.count(L))
                    st.erase(L);
                else
                    st.insert(L);
            }
            if (R < N - 1) {
                if (st.count(R + 1))
                    st.erase(R + 1);
                else
                    st.insert(R + 1);
            }
        } else {
            auto it = st.upper_bound(L);
            yes_no(it == st.end() || *it > R);
        }
    }
}
