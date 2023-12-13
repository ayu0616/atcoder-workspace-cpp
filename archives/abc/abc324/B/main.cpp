#include "../../lib.hpp"

// const int MOD = 998244353;
// const int MOD = 1000000007;
// const int MOD = 1000000009;

// using mint = static_modint<MOD>;

int main()
{
    ll N;
    cin>>N;
    while(N%2==0) N/=2;
    while(N%3==0) N/=3;
    if(N==1) cout << "Yes" << endl;
    else cout << "No" << endl;
}
