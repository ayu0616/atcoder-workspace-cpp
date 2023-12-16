#include "../../lib.hpp"

// constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
// constexpr int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main() {
    char s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    int s = abs(s1-s2), t = abs(t1-t2);
    yes_no(s==t || (s==1 && t==4) || (s==4 && t==1) || (s==3 && t==2) || (s==2 && t==3));
}
