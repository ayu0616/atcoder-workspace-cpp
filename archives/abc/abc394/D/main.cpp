#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"
#include "hassaku/binary-search.hpp"
#include "hassaku/cumulative-sum.hpp"
#include "hassaku/doubly-linked-list.hpp"
#include "hassaku/gcd.hpp"
#include "hassaku/prime.hpp"
#include "hassaku/union-find.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    cout << fixed << setprecision(18);
    string S;
    cin >> S;
    stack<char> st;
    rep(i, S.size()) {
        char c = S[i];
        if (c == '(' || c == '[' || c == '<')
            st.push(c);
        else {
            if (st.empty()) {
                cout << "No" << endl;
                return 0;
            }
            char top = st.top();
            st.pop();
            if (c == ')' && top != '(') {
                cout << "No" << endl;
                return 0;
            }
            if (c == ']' && top != '[') {
                cout << "No" << endl;
                return 0;
            }
            if (c == '>' && top != '<') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if (!st.empty()) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
