#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    char p, q;
    cin>>p>>q;
    vector<int> d = {0, 3, 4, 8, 9, 14, 23};
    cout<<abs(d[p-'A'] - d[q-'A'])<<endl;
}
