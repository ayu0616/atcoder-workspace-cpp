#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

char switch_upper_lower(char c) {
    if ('a' <= c && c <= 'z') {
        return c - 'a' + 'A';
    } else if ('A' <= c && c <= 'Z') {
        return c - 'A' + 'a';
    } else {
        return c;
    }
}

int main() {
    cout << fixed << setprecision(18);
    string S;
    cin >> S;
    int N = S.size();
    vi pair(N, -1);
    vi st;
    rep(i, N) {
        if (S[i] == '(') {
            st.push_back(i);
        } else if (S[i] == ')') {
            int j = st.back();
            st.pop_back();
            pair[i] = j;
            pair[j] = i;
        }
    }
    bool rev = false;
    string ans = "";
    int i = 0;
    while (i < N) {
        if (S[i] == '(' || S[i] == ')') {
            i = pair[i];
            rev = !rev;
        } else {
            ans += rev ? switch_upper_lower(S[i]) : S[i];
        }
        if (rev) {
            i--;
        } else {
            i++;
        }
    }
    cout << ans << endl;
}
