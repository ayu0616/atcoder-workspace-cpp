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
    vl A(N);
    cin >> A;
    stack<ll> st;
    rep(i, N) {
        if (st.size() == 0) {
            st.push(A[i]);
        } else {
            while (st.size() && st.top() == A[i]) {
                st.pop();
                A[i]++;
            }
            st.push(A[i]);
        }
    }
    cout << st.size() << endl;
}
