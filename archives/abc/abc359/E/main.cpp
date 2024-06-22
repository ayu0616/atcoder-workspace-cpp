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
    ll N;
    cin >> N;
    vl H(N);
    cin >> H;
    vl ans(N, 0);
    vi nearest_bigger(N, -1);  // 自身より左で自信以上のもののうち最も右のもの
    stack<int> st;
    rep(i, N) {
        while (!st.empty() && H[st.top()] < H[i]) {
            nearest_bigger[i] = st.top();
            st.pop();
        }
        if (!st.empty() && H[st.top()] >= H[i]) {
            nearest_bigger[i] = st.top();
        }
        st.push(i);
    }
    if (HASSAKU_DEBUG) {
        for (int i = 0; i < N; i++) {
            assert(nearest_bigger[i] < i);
        }
    }
    ll m = 0;
    int mi = 0;
    rep(i, N) {
        if (H[i] >= m) {
            m = H[i];
            mi = i;
            ans[i] = 1 + (i + 1) * m;
        } else {
            int nb = nearest_bigger[i];
            if (nb == -1) {
                ans[i] = (i + 1) * H[i];
            } else {
                ans[i] = ans[nb] + (i - nb) * H[i];
            }
        }
    }
    if (HASSAKU_DEBUG) {
        rep(i, N - 1) { assert(ans[i] < ans[i + 1]); }
    }
    cout << ans << endl;
}
