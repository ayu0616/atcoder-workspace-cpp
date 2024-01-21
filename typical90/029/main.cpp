#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    int W, N;
    cin >> W >> N;

    SegTree st(W);
    st.update(0, W, 0);

    rep(i, N) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int tmp = st.query(l, r + 1);
        st.update(l, r + 1, tmp - 1);
        cout << -st.query(l, r + 1) << endl;
    }
}
