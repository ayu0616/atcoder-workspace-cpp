#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    rep(i, 2*n){
        cout << s[i / 2];
    }
    cout << endl;
}
